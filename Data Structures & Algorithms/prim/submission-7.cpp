class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        // Prim's algorithm
        // 1. Build a adj List - <v,wt>
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]}); // undirected
        }
        // Book keeping - unordered_set of Visited vertices, MST edges, Minheap <wt, u, v>
        unordered_set<int> visited;
        vector<vector<int>> MST;
        int totalCost = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;

        // Push the zeroth vertex edges
        for(auto &[v, wt] : adj[0])
            minHeap.push({wt, 0, v});
        visited.insert(0);
        // Pick the smallest element with destination node that is not visited.
        while(!minHeap.empty() && visited.size() != n)
        {
            auto [wt, u, v] = minHeap.top();
            minHeap.pop();
            if(visited.count(v))
                continue;
            
            MST.push_back({u,v});
            totalCost += wt;

            for(auto &[v2, wt2] : adj[v])
                if(!visited.count(v2))
                    minHeap.push({wt2, v, v2});
            visited.insert(v);
        }
        
        return (visited.size() == n) ? totalCost : -1;
    }
};

