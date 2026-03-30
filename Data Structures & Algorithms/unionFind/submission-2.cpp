class UnionFind {
public:
    UnionFind(int n) {
        rank.resize(n, 1);
        parent.resize(n, 0);
        for(auto i = 0; i < n;++i)
            parent[i] = i;
        numComponents = n;
    }

    int find(int x) {
        int result = parent[x];
        if(result != x)
            result = find(parent[x]);
        return result;        
    }

    bool isSameComponent(int x, int y) {
        return (find(x) == find(y));
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
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

    int getNumComponents() {
        return numComponents;
    }
    vector<int> rank;
    vector<int> parent;
    int numComponents;
};
