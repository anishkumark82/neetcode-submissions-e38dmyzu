class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        // Create an adj List
        vector<vector<pair<int,int>>> adj(points.size());
        for(auto i = 0; i < points.size()-1; ++i)
            for(auto j = i+1; j < points.size(); ++j)
            {
                int dist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_set<int> visited;
        int total = 0;
        // Push all edges of 0.
        for(auto [v, d] : adj[0])
            minHeap.push({d, v});

        visited.insert(0);

        while(!minHeap.empty() && visited.size() < points.size())
        {
            auto [d, u] = minHeap.top();
            minHeap.pop();
            
            if(visited.count(u))
                continue;
            
            visited.insert(u);
            total += d;

            for(auto [v, d2] : adj[u])
                if(!visited.count(v))
                    minHeap.push({d2, v});
        }
        return total;
    }
};
