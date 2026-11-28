class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Minimum Spanning Tree Algorithm -- Prim's algorithm
        // Build an adj List
        // Pair contains point index and distance
        vector<vector<pair<int, int>>> adj(points.size());
        for(int i = 0; i < points.size(); ++i)
            for(int j = i+1; j < points.size(); ++j)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        
        int minCost = 0;
        unordered_set<int> visited;
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;

        // Insert the edges of vertex 0
        for(auto &[v, wt] : adj[0])
            minHeap.push({wt, 0, v});
        
        visited.insert(0);

        while(!minHeap.empty() && visited.size() != points.size())
        {
            auto [wt, u, v] = minHeap.top();
            minHeap.pop();

            // check if V is already visited
            if(visited.count(v))
                continue;
            
            minCost += wt;

            for(auto &[v2, d] : adj[v])
                if(!visited.count(v2))
                    minHeap.push({d, v, v2});
            visited.insert(v);
        }

        return minCost;
    }
};
