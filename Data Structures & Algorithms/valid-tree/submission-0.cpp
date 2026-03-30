struct UnionFind{
    UnionFind(int n)
    {
        numComponents = n;
        rank.resize(n, 1);
        parent.resize(n);
        for(auto i = 0; i < parent.size(); ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        int result = parent[x];
        if(x != parent[x])
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
        numComponents--;
        return true;
    }

    int getNumComponents()
    {
        return numComponents;
    }
    vector<int> rank;
    vector<int> parent;
    int numComponents;
};
class Solution {
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        UnionFind uf(n);
        for(auto &e: edges)
            if(!uf._union(e[0], e[1]))
                return false;
        
        return (uf.getNumComponents() == 1);
    }
};
