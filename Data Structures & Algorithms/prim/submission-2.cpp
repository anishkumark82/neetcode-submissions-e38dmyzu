class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &e : edges)
        {
            adjList[e[0]].push_back({e[1], e[2]});// {v, w}
            adjList[e[1]].push_back({e[0], e[2]});// {v, w}
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;
        unordered_set<int> visited;
        int minSpan = 0;

        // Visit 0 Node
        vector<pair<int,int>> &nbrs = adjList[0];
        for(auto &nbr : nbrs)
            minHeap.push(make_tuple(nbr.second, 0, nbr.first));
        visited.insert(0);

        while(visited.size() != n && !minHeap.empty())
        {
            tuple<int,int,int> cur = minHeap.top();
            minHeap.pop();

            int w = get<0>(cur);
            int u = get<1>(cur);
            int v = get<2>(cur);

            if(visited.find(v) != visited.end()) // already visited
                continue;
            
            minSpan += w;

            vector<pair<int,int>> &nbrs = adjList[v];
            for(auto &nbr : nbrs)
            {
                if(visited.find(nbr.first) != visited.end())
                    continue;
                minHeap.push(make_tuple(nbr.second, v, nbr.first));
            }
            visited.insert(v);
        }
        return (visited.size() != n) ? -1 : minSpan;
    }
};

