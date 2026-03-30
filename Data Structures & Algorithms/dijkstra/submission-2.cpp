class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int,int>>> adjList(n);

        // Pair contains v & w
        for(auto &e: edges)
            adjList[e[0]].push_back({e[1], e[2]});

        // adjList :  0 - {1,10}, {2, 3}
        //            1 - {3,2}
        //            2 - {1,4}, {3,8}, {4,2}
        //            3 - {4,5}
        //            4 - {}  
        // shortest - 0 : 0,  
        // minHeap - {10, 1} 
        // w = 3, v = 2
        // nb = {1,4}  - w2 = , n = 
        unordered_map<int, int> shortest;
        // pair will contain -- w, v
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        minHeap.push({0, src});
        while(!minHeap.empty())
        {
            auto [w, v] = minHeap.top();
            minHeap.pop();
            
            if(shortest.find(v) != shortest.end()) // Already visited
                continue;
            
            // Update the map
            shortest[v] = w;

            // Find its neighbors
            auto &nbs = adjList[v];
            for(auto &nb : nbs)
            {
                auto w2 = nb.second;
                auto n2 = nb.first;
                if(shortest.find(n2) == shortest.end())
                    minHeap.push({w2 + w, n2});
            }
        }

        for(auto i = 0; i < n; ++i)
        {
            if(shortest.find(i) == shortest.end())
                shortest[i] = -1;
        }
        return shortest;
    }
};
