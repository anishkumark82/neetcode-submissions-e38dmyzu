using PQ_PAIR = pair<int,int>;
class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &e : edges)
        {
            adjList[e[0]].push_back({e[1], e[2]});// {v, w}
            adjList[e[1]].push_back({e[0], e[2]});// {v, w}
        }

        priority_queue<PQ_PAIR, vector<PQ_PAIR>, greater<PQ_PAIR>> minHeap;
        unordered_set<int> visited;
        int minSpan = 0;
        minHeap.push({0,0});
        while(visited.size() != n && !minHeap.empty())
        {
            PQ_PAIR cur = minHeap.top();
            minHeap.pop();

            int w = cur.first;
            int v = cur.second;

            if(visited.find(v) != visited.end()) // already visited
                continue;
            
            minSpan += w;

            vector<pair<int,int>> &nbrs = adjList[v];
            for(auto &nbr : nbrs)
            {
                if(visited.find(nbr.first) != visited.end())
                    continue;
                minHeap.push({nbr.second, nbr.first});
            }
            visited.insert(v);
        }
        return (visited.size() != n) ? -1 : minSpan;
    }
};

