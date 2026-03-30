using INT_TUPLE = tuple<int,int,int>;
struct UnionFind{
    UnionFind(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        numComp = n;
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
            parent[pY] = pX;
            rank[pX] += rank[pY];
        }
        else
        {
            parent[pX] = pY;
            rank[pY] += rank[pX];
        }
        numComp--;
        return true;
    }
    int getNumberOfComponents()
    {
        return numComp;
    }
    vector<int> rank;
    vector<int> parent;
    int numComp;
};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        UnionFind uf(n);
        priority_queue<INT_TUPLE, vector<INT_TUPLE>, greater<INT_TUPLE>> minHeap;
        vector<pair<int,int>> MST;
        int total = 0;
        for(auto &e : edges)
            minHeap.push(make_tuple(e[2], e[0], e[1]));

        while(!minHeap.empty() && MST.size() != n-1)
        {
            auto [w,u,v] = minHeap.top();
            minHeap.pop();

            if(!uf._union(u,v))
                continue;
            
            MST.push_back({u,v});
            total += w;
        }
        return (uf.getNumberOfComponents() != 1) ? -1 : total;
    }

};
