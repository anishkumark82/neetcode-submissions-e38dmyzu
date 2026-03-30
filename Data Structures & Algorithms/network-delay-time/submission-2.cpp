class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1); // 0 is not a valid edge
        // pair contains v, t
        for(auto &t : times)
            adj[t[0]].push_back({t[1], t[2]});

        unordered_map<int, int> shortest;
        int maxVal = -1;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, k});
        // shortest - 1 : 0, 2: 1
        // minHeap - {4, 4}
        // w1 = 1, u = 2
        // 
        // maxVal = 1
        while(!minHeap.empty() && shortest.size() != n)
        {
            auto [w1, u] = minHeap.top();
            minHeap.pop();
            
            // Check if already visited
            if(shortest.find(u) != shortest.end())
                continue;

            shortest[u] = w1;
            maxVal = max(maxVal, w1);

            for(auto [v, w2] : adj[u])
                if(shortest.find(v) == shortest.end())
                    minHeap.push({w1 + w2, v});
        }

        return (shortest.size() == n) ? maxVal : -1;
    }
};
