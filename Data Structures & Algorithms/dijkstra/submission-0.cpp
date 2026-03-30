using PAIRINT = pair<int,int>;
class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        // Dijkstra's Algorithm

        // Create an adjcency List 
        vector<vector<PAIRINT>> adj(n);
        for(auto &e : edges)
            adj[e[0]].push_back({e[1], e[2]}); // {dest, dist}

        unordered_map<int, int> shortestPath;
        // pair{distance, dest}
        priority_queue<PAIRINT, vector<PAIRINT>, greater<PAIRINT>> minHeap;
        minHeap.push({0, src});

        while(!minHeap.empty())
        {
            PAIRINT p = minHeap.top();
            minHeap.pop();
            if(shortestPath.find(p.second) != shortestPath.end()) // already visited
                continue;

            shortestPath[p.second] = p.first;
            vector<PAIRINT> &neighbors = adj[p.second];
            // add the distance from p[1] to neighboring nodes
            for(auto i = 0; i < neighbors.size(); ++i)
                minHeap.push({p.first+neighbors[i].second, neighbors[i].first});
        }

        if(shortestPath.size() != n)
        {
            for(auto i = 0; i < n; ++i)
                if(shortestPath.find(i) == shortestPath.end())
                    shortestPath[i] = -1;
        }
        return shortestPath;
    }
};
