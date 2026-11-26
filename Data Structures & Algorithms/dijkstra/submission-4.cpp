class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int,int>>> adj(n);
        // Each adj node contain a vector of pair<v, w>
        for(auto &e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        // Priority queue with w, v
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, src});
        vector<int> out(n, -1);
        while(!minHeap.empty())
        {
            // extract the node with the smallest weight
            auto [wt, u] = minHeap.top();
            minHeap.pop();

            // Visited ???
            if(out[u] != -1)
                continue;

            out[u] = wt;

            for(auto [v, w] : adj[u])
                // not already visited
                if(out[v] == -1)
                    minHeap.push({wt+w,v}); // include the wt to reach the current node
        }
        unordered_map<int, int> res;
        for(auto i = 0; i < n; ++i)
            res[i] = out[i];
        return res;
    }
};
