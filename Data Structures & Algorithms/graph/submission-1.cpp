class Graph {
    bool _dfs(int src, int dst, unordered_set<int>& visited)
    {
        if(src == dst)
            return true;
        
        if(visited.find(src) != visited.end())
            return false;
        
        visited.insert(src);
        unordered_set<int> &neighbors = adjList[src];
            // Get a reference using []
        for(auto itr = neighbors.begin(); itr != neighbors.end(); ++itr)
            if (_dfs(*itr, dst, visited))
                return true;
        
        visited.erase(src);
        return false;
    }
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adjList[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if(adjList.find(src) == adjList.end()) // cannot find the source
            return false;

        auto itr = adjList[src].find(dst);
        if(itr == adjList[src].end())
            return false;
        adjList[src].erase(itr);
        return true;
    }

    bool hasPath(int src, int dst) {
        unordered_set<int> visited;
        return _dfs(src, dst, visited);
    }
    unordered_map<int, unordered_set<int>> adjList; 
};
