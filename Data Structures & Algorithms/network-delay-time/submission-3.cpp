
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra's Algorithm
        vector<vector<pair<int,int>>> adj(n+1); // --> 1 to n
        for(auto &t : times)
            adj[t[0]].push_back({t[1], t[2]}); // u,v,wt

        unordered_map<int,int> shortest; // Can cover visited also
        int minTime = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});
        while(!minHeap.empty() && shortest.size() != n)
        {
            auto [wt1, u] = minHeap.top();
            minHeap.pop();

            if(shortest.find(u) != shortest.end())
                continue;
            
            shortest[u] = wt1;
            minTime = max(minTime, wt1); // TBD ?? Should we go for the max ??

            for(auto [v, wt2] : adj[u])
                if(shortest.find(v) == shortest.end())
                    minHeap.push({wt1+wt2, v});
        }

        return (shortest.size() == n) ? minTime : -1;
    }
};
