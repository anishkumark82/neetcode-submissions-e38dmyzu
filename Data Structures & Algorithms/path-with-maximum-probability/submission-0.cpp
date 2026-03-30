class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int,double>>> adj(n);
        for(auto i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});

            // Since undirected
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        unordered_map<int, double> shortest;
        // pair weight (success prob)
        priority_queue<pair<double,int>> maxHeap;
        maxHeap.push({1.0, start_node});

        while(!maxHeap.empty() && shortest.size() != n)
        {
            auto [p1, u] = maxHeap.top();
            maxHeap.pop();

            if(shortest.find(u) != shortest.end())
                continue;
            
            shortest[u] = p1;

            for(auto [v, p2] : adj[u])
                if(shortest.find(v) == shortest.end())
                    maxHeap.push({p1*p2, v});
        }
        return (shortest.find(end_node) == shortest.end())? 0.0 : shortest[end_node];
    }
};