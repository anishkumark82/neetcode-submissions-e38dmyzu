using INT_TUPLE = tuple<int,int,int>;

struct UnionFind{
    UnionFind(int n)
    {
        rank.resize(n,1);
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
    
    int getNumComponents()
    {
        return numComp;
    }
    vector<int> rank;
    vector<int> parent;
    int numComp;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<INT_TUPLE, vector<INT_TUPLE>, greater<INT_TUPLE>> minHeap;
        UnionFind uf(points.size());
        for(auto i = 0; i < points.size(); ++i)
            for(auto j = i+1; j < points.size(); ++j)
            {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                minHeap.push(make_tuple(d, i, j));
            }
        vector<pair<int,int>> MST;
        int total = 0;
        while(!minHeap.empty() && MST.size() != points.size()-1)
        {
            auto [d, u, v] = minHeap.top();
            minHeap.pop();

            if(!uf._union(u,v))
                continue;
            
            total += d;
            MST.push_back({u,v});
        }

        return total;
    }
};
