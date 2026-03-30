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
    bool unionEdges(int u, int v)
    {
        int pU = findParent(u);
        int pV = findParent(v);
        
        if(pU == pV)
            return false;
        
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
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        // Create a Minheap of edges based on weights 
        priority_queue<PQ_TUPLE, vector<PQ_TUPLE>, greater<PQ_TUPLE>> minHeap;
        for (auto &e : edges)
            minHeap.push(make_tuple(e[2], e[0], e[1]));
        
        int minCost = 0;
        int mstCnt = 0;
        UnionFind U(n);
        while(mstCnt != n-1 && !minHeap.empty())
        {
            PQ_TUPLE cur = minHeap.top();
            minHeap.pop();
            if(U.unionEdges(get<1>(cur), get<2>(cur)))
            {
                minCost += get<0>(cur);
                mstCnt++;
            }
        }
        return (mstCnt != n-1) ? -1 : minCost;
    }
};
