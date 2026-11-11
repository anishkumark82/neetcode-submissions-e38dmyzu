class UnionFind {
public:
    UnionFind(int n) {
        numComp = n;
        rank.resize(n, 1);
        parent.resize(n);
        for(auto i = 0; i < n; ++i)
            parent[i] = i;
    }
    // determine parent and also optimize the ht to point to the final parent
    int find(int x) {
        int result = parent[x];
        if(result != x)
        {
            result = find(parent[x]);
            parent[x] = result;
        }
        return result;
    }

    bool isSameComponent(int x, int y) {
        return(find(x) == find(y));
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if(pX == pY) // Cycle detected
            return false;
        
        if(rank[pX] >= rank[pY])
        {
            parent[pY] = pX;
            rank[pX] += rank[pY];
        }
        else
        {
            parent[pX] = pY;
            rank[pY] += pX;
        }
        numComp--;
        return true;
    }

    int getNumComponents() {
        return numComp;
    }
    vector<int> rank;
    vector<int> parent;
    int numComp;
};
