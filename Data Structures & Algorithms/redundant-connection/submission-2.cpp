class UnionSet{
public:
    UnionSet(int n)
    {
        rank.resize(n+1, 1);
        parent.resize(n+1);
        for(auto i = 0; i <= n; ++i)
            parent[i] = i;
        
    }
    int find(int u)
    {
        if(parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool findUnion(int u, int v)
    {
        int pU = find(u);
        int pV = find(v);
        if(pU == pV) // Then we have a cycle (common parent)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionSet U(edges.size());
        for(auto &e : edges)
            if(!U.findUnion(e[0], e[1]))
                return e;
        return {-1,-1};
    }
};
