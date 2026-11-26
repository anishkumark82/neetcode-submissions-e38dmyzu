class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Djikstra's algorithm
        
        // 1. Build Adjacency List
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &t : times)
            adj[t[0]].push_back({t[1], t[2]});

        // Book keeping
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; // [wt, v]
        unordered_set<int> visited;
        int max_delay = 0;
        minHeap.push({0, k});

        while(!minHeap.empty() && visited.size() != n)
        {
            auto [wt, u] = minHeap.top();
            minHeap.pop();

            if(visited.count(u))
                continue;
                
            visited.insert(u);
            max_delay = max(max_delay,wt);

            for(auto &[v, w] : adj[u])
                if(!visited.count(v))
                    minHeap.push({wt+w, v});
        }
        
        return (visited.size() == n) ? max_delay : -1;
    }
};
