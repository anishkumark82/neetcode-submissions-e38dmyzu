class UnionFind{
public:
    UnionFind(int n)
    {
        rank.resize(n+1, 1);
        parent.resize(n+1);
        numComp = n;
        for(auto i = 1; i < n+1; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        int result = parent[x];
        if(result != x)
        {
            result = find(parent[x]);
            parent[x] = result;
        }
        return result;
    }

    bool _union(int x, int y)
    {
        int pX = find(x);
        int pY = find(y);
        if(pX == pY) // found a cycle
            return false;
        
        if(rank[pX] >= rank[pY])
        {
            parent[pY] = parent[pX];
            rank[pX] += rank[pY];
        }
        else
        {
            parent[pX] = parent[pY];
            rank[pY] += rank[pX];
        }
        numComp--;
        return true;
    }
    int getNumComponents()
    {
        return numComp;
    }
private:
    int numComp;
    vector<int> parent;
    vector<int> rank;
};
class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());

        for(auto &e : edges)
            if(!uf._union(e[0], e[1]))
                return e;
        
        throw;
    }
};
