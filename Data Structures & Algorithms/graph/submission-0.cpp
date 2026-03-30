class Graph {
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adjMap[src].insert(dst);        
    }

    bool removeEdge(int src, int dst) {
        auto itr = adjMap[src].find(dst);
        if(itr != adjMap[src].end())
        {
            adjMap[src].erase(itr);
            return true;
        }
        return false;
    }
    bool _dfs(int u, int v)
    {
        if(u == v)
            return true;
        
        if(visited.find(u) != visited.end())
            return false;
        
        visited.insert(u);
        for(auto itr = adjMap[u].begin(); itr != adjMap[u].end(); ++itr)
            if(_dfs(*itr, v) == true)
                return true;
            
        auto itr = visited.find(u);
        visited.erase(itr);
        return false;
    }

    bool hasPath(int src, int dst) {    
        return _dfs(src, dst);
    }
    unordered_map<int,unordered_set<int>> adjMap;
    unordered_set<int>visited;


};
