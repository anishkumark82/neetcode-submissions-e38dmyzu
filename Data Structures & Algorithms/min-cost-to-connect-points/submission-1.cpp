using PQ_PAIR = pair<int,int>;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        vector<vector<pair<int,int>>> adjList(pts.size());
        
        for(auto i = 0; i < pts.size(); ++i)
        {
            int x1 = pts[i][0];
            int y1 = pts[i][1];
            for(auto j = i+1; j < pts.size(); ++j)
            {
                int x2 = pts[j][0];
                int y2 = pts[j][1];    
                int dst = abs(x1 - x2) + abs(y1 - y2);
                adjList[i].push_back({j, dst});
                adjList[j].push_back({i, dst});
            }
        }
        unordered_set<int>visited;
        int minCost = 0;
        priority_queue<PQ_PAIR, vector<PQ_PAIR>, greater<PQ_PAIR>> minHeap;
        minHeap.push({0,0});

        while(visited.size() != pts.size() && !minHeap.empty())
        {
            PQ_PAIR cur = minHeap.top();
            minHeap.pop();

            int w = cur.first;
            int v = cur.second;

            if(visited.find(v) != visited.end())
                continue;
                
            minCost += w;
            vector<pair<int,int>> &nbrs = adjList[v];
            for(auto &nbr : nbrs)
            {
                if(visited.find(nbr.first) != visited.end())
                    continue;
                minHeap.push({nbr.second, nbr.first});
            }
            visited.insert(v);
        }
        return minCost;
    }
};
