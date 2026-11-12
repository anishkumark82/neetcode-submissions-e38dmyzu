class UnionFind{
public:
    UnionFind(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        numComp = n;
        for(auto i = 0; i < n; ++i)
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

        if(pX == pY) // cycle or already part of the component
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
        numComp--;
        return true;
    }
       
    int getNumberOfComponents()
    {
        return numComp;
    }

private:
    vector<int> rank;
    vector<int> parent;
    int numComp;
};
class Solution {

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for(auto &e : edges)
            uf._union(e[0], e[1]); // nobody is looking for cycles so no need to check the cycles
        
        return uf.getNumberOfComponents();
    }
};
