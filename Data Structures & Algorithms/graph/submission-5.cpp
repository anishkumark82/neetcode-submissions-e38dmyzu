class Graph {
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adjList[src].insert(dst);
        if(!adjList.count(dst))
            adjList[dst] = {};
    }

    bool removeEdge(int src, int dst) {
        if(!adjList.count(src) || !adjList[src].count(dst))
            return false;
        adjList[src].erase(dst);
        return true;
    }

    bool hasPath(int src, int dst) {
        // BFS is better because it finds the shortest path if it exists
        queue<int> Q;
        unordered_set<int>visited;

        Q.push(src);
        visited.insert(src);

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                auto v = Q.front();
                Q.pop();

                if(v == dst)
                    return true;
                
                // find its neighbors
                for(auto &n : adjList[v])
                    if(!visited.count(n))
                    {
                        Q.push(n);
                        visited.insert(n);
                    }
            }
        }
        return false;
    }
    unordered_map<int, unordered_set<int>> adjList;
};
