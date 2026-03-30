class Solution {
public:
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
        numC--;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        numC = edges.size(); // n edges with n vertices
        rank.resize(numC+1, 1);
        parent.resize(numC+1);
        for(auto i = 1; i < numC+1; ++i)
            parent[i] = i;
        for(auto &e : edges)
            if(!_union(e[0], e[1]))
                return e; 
        return {-1,-1};        
    }
    
private:
    int numC;
    vector<int>rank;
    vector<int>parent;
};
