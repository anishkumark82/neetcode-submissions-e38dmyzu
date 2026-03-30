class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        for(auto i = 0; i < n; ++i)
            parent[i] = i;
        rank.resize(n, 1);
        numComponents = n;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool isSameComponent(int x, int y) {
        return (find(x) == find(y));
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if(pX == pY) // connected or have cycle
            return false;

        // otherwise check the rank
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
        numComponents--;
        return true;
    }

    int getNumComponents() {
        return numComponents;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int numComponents;
};
