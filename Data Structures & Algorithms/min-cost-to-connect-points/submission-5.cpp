class UnionFind{
public:
    UnionFind(int n)
    {
        numComp = n;
        rank.resize(n, 1);
        parent.resize(n);
        for(auto i = 0; i < parent.size(); ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        int result = parent[x];
        if(result != x) // path compression
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

        if(pX == pY) // Already connected
            return false;
        
        if(rank[pX] >= rank[pY])
        {
            parent[pY] = pX;
            rank[pX] += rank[pY];
        }
        else
        {
            parent[pX] =  pY;
            rank[pY] += rank[pX];
        }
        numComp--;
        return true;
    }
private:
    vector<int> rank;
    vector<int> parent;
    int numComp;
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;
        UnionFind uf(points.size());
        // O(n^2)
        for(auto i = 0; i < points.size()-1; ++i)
            for(auto j = i+1; j < points.size(); ++j)
            {
                int dist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                minHeap.push(make_tuple(dist, i, j)); 
            }

        int total = 0;
        while(!minHeap.empty())
        {
            auto [d, u, v] = minHeap.top();
            minHeap.pop();
            if(uf._union(u,v))
                total += d;
        }
        return total;
    }
};
