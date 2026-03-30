using INT_TUPLE = tuple<int,int,int>;

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int,int>>> adj(n);

        //n=5
        //edges=[[0,1,10],[0,2,3],[1,3,2],[2,1,4],[2,3,8],[2,4,2],[3,4,5]]
        
        for(auto &e : edges)
        {
            // u,v,w
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int total = 0;
        vector<pair<int,int>> MST;
        priority_queue<INT_TUPLE, vector<INT_TUPLE>, greater<INT_TUPLE>> minHeap;
        unordered_set<int> visited;

        // Push the edges from 0th node
        for(auto [v, w] : adj[0])
            minHeap.push(make_tuple(w, 0, v));
        visited.insert(0);

        while(!minHeap.empty() && MST.size()!= n-1)
        {
            auto [w, u, v] = minHeap.top();
            minHeap.pop();

            if(visited.find(v) != visited.end())
                continue;

            MST.push_back({u,v});
            total += w;

            visited.insert(v);
            for(auto [v2, w2] : adj[v])
                if(visited.find(v2) == visited.end())
                    minHeap.push(make_tuple(w2,v,v2));
        }
        return (MST.size() == n-1) ? total : -1;
    }
};

