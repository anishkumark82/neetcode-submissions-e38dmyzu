class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int,int>>>adjList(n);

        for(auto &e : edges)
        {
            adjList[e[0]].push_back({e[1], e[2]}); //{dest, weight}
            adjList[e[1]].push_back({e[0], e[2]}); //{dest, weight}
        }

        unordered_set<int>visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int minVal = 0;
        // Visit 0
        vector<pair<int,int>> &nbrs = adjList[0];
        for(auto &nbr : nbrs)
            minHeap.push({nbr.second,0, nbr.first});
        visited.insert(0);

        while(!minHeap.empty())
        {
            int w = minHeap.top()[0];
            int u = minHeap.top()[1];
            int v = minHeap.top()[2];
            minHeap.pop();
            if(visited.find(v) != visited.end())
                continue;

            minVal += w;
            vector<pair<int,int>> &nbrs = adjList[v];
            for(auto &nbr : nbrs)
            {
                if(visited.find(nbr.first) != visited.end())
                    continue;
                minHeap.push({nbr.second, v, nbr.first});
            }
            visited.insert(v);
        }
        return (visited.size() != n) ? -1 : minVal;
    }
};

