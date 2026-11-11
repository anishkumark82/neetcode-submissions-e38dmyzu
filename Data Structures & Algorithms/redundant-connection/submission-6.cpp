class UnionFind{
public:
    UnionFind(int n)
    {
        rank.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n+1; ++i)
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
        if(pX == pY) // found the node which caused the cycle
            return false;
        
        if(rank[pX] >= rank[pY])
        {
            rank[pX] += rank[pY];
            parent[pY] = parent[pX];
        }
        else
        {
            rank[pY] += rank[pX];
            parent[pX] = parent[pY];
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
        UnionFind uf(edges.size());
        for(auto &e: edges)
            if(!uf._union(e[0], e[1]))
                return {e[0], e[1]};
        return {-1,-1};
    }
};
