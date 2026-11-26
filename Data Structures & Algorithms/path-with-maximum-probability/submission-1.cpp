class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Dijkstra's algorithm

        // 1. Build an adj list
        vector<vector<pair<int, double>>> adj(n);
        for(auto i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Book keeping for the algorithm
        unordered_set<int> visited;
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start_node});
        double retProb = 0.0;
        while(!maxHeap.empty())
        {
            auto [p1, u] = maxHeap.top();
            maxHeap.pop();

            if(visited.count(u))
                continue;
            
            visited.insert(u);
            if(u == end_node)
            {
                retProb = p1;
                break;
            }
            for(auto &[v, p2] : adj[u])
                if(!visited.count(v))
                    maxHeap.push({p1*p2,v});
        }
        return retProb;
    }
};