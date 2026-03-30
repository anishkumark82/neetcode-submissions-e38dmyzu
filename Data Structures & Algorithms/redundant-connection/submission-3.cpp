class UnionFind{
public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        for(auto i = 0; i < n+1; ++i)
            parent[i] = i;
        rank.resize(n+1, 1);
    }

    int findParent(int u)
    {
        int result = parent[u];
        if(result != u)
        {
            result = findParent(parent[u]);
            parent[u] = result;
        }
        return result;
    }

    bool findUnion(int u, int v)
    {
        int pU = findParent(u);
        int pV = findParent(v);
        
        if(pU == pV) // found a cycle
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
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind U(edges.size());

        for(auto &e : edges)
        {
            if(U.findUnion(e[0], e[1]) != true)
                return e;
        }
        return {-1,-1};
    }
};
