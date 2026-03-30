class Graph {
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adjList[src].insert(dst);
        
    }

    bool removeEdge(int src, int dst) {
        if(adjList.find(src) == adjList.end())
            return false;

        auto itr = adjList[src].find(dst);
        if(itr == adjList[src].end())
            return false;
        
        adjList[src].erase(itr);
        return true;
    }

    bool hasPath(int src, int dst) {
        // Validity check
        if(adjList.find(src) == adjList.end())
            return false;
        
        unordered_set<int> visited;
        queue<int> Q;
        Q.push(src);
        visited.insert(src);

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                int cur = Q.front();
                Q.pop();
                if(cur == dst)
                    return true;
                
                unordered_set<int> &nb = adjList[cur];
                for(auto itr = nb.begin(); itr != nb.end(); ++itr)
                    if(visited.find(*itr) == visited.end())
                        Q.push(*itr);
            }
        }
        return false;
    }
    unordered_map<int, unordered_set<int>> adjList;
};
