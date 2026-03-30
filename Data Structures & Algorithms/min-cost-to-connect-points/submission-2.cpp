using PQ_TUPLE = tuple<int,int,int>; // weight, u, v
class UnionFind{
public:
    UnionFind(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        for(auto i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if(parent[u] != u)
            parent[u] = findParent(parent[u]);
        return parent[u];
    }

    bool unionEdge(int u, int v)
    {
        int pU = findParent(u);
        int pV = findParent(v);
        
        if(pU == pV)
            return false; // there is a cycle
        
        if(rank[pU] >= rank[pV])
        {
            rank[pU] += rank[pV];
            parent[pV] = pU;
        }
        else
        {
            rank[pV] += rank[pU];
            parent[pU] = pV;
        }
        return true;
    }
private:
    vector<int> rank;
    vector<int> parent;
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        priority_queue<PQ_TUPLE, vector<PQ_TUPLE>, greater<PQ_TUPLE>> minHeap;
        for(auto i = 0; i < pts.size()-1; ++i)
        {
            int x1 = pts[i][0];
            int y1 = pts[i][1];
            for(auto j = i+1; j < pts.size(); ++j)
            {
                int x2 = pts[j][0];
                int y2 = pts[j][1];
                int w = abs(x1-x2) + abs(y1-y2);
                minHeap.push(make_tuple(w, i, j));
            }
        }
        int minCost = 0;
        int mstCnt = 0;
        UnionFind U(pts.size());
        while(mstCnt != pts.size()-1)
        {
            PQ_TUPLE cur = minHeap.top();
            minHeap.pop();
            if(U.unionEdge(get<1>(cur), get<2>(cur)))
            {
                minCost += get<0>(cur);
                mstCnt++;
            }
        }
        return minCost;
    }
};
