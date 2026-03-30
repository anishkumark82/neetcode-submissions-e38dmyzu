class UnionSet{
public:
    UnionSet(int n)
    {
        parent.resize(n);
        for(auto i = 0; i < n; ++i)
            parent[i] = i;
        
        rank.resize(n, 1);
        numComponents = n;
    }
    int find(int u)
    {
        if(parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void findUnion(int u, int v)
    {
        int pU = find(u);
        int pV = find(v);

        if(pV == pU)
            return;
        
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
        numComponents--;
    }
    int findConnectedComponents()
    {
        return numComponents;
    }
    vector<int> parent;
    vector<int> rank;
    int numComponents;
};
class Solution {

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionSet U(n);
        for(auto &e : edges)
            U.findUnion(e[0], e[1]);
        
        return U.findConnectedComponents();
    }

};
