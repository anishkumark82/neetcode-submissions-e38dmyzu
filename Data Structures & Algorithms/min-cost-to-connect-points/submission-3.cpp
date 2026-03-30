using INT_TUPLE = tuple<int,int,int>;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        for(auto i = 0; i < points.size(); ++i)
        {
            for(auto j = i+1; j < points.size(); ++j)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<pair<int,int>> MST;
        int total = 0;
        priority_queue<INT_TUPLE, vector<INT_TUPLE>, greater<INT_TUPLE>> minHeap;
        unordered_set<int> visited;
        // Add first point and its neighbors
        for(auto [v, d] : adj[0])
            minHeap.push(make_tuple(d,0,v));
        visited.insert(0);

        while(!minHeap.empty() && visited.size() != points.size())
        {
            auto [d, u, v] = minHeap.top();
            minHeap.pop();

            if(visited.find(v) != visited.end())
                continue;
            
            total += d;
            MST.push_back({u,v});

            for(auto [v2, d2] : adj[v])
                if(visited.find(v2) == visited.end())
                    minHeap.push(make_tuple(d2, v, v2));
            visited.insert(v);                
        }
        return total;
    }
};
