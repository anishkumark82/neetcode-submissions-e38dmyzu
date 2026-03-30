class unionFind
{
public:
    unionFind(int n)
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

        if(pX == pY)
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
    vector<int>parent;
    vector<int>rank;
    int numComponents; 

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unionFind uf(n);
        for(auto &e : edges)
            uf._union(e[0], e[1]);

        return uf.getNumComponents();
    }
};
