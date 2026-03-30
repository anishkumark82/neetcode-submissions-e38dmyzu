class Solution {
private:
    bool _dfs(int i, vector<vector<int>> &adjList, vector<bool> &visited,
              vector<bool> &path, vector<int> &topSort) {
        if(path[i])
            return false;

        if(visited[i])
            return true;
        
        visited[i] = true;
        path[i] = true;
        // Explore all its neighbors
        vector<int> &nbrs = adjList[i];
        for(auto &n : nbrs)
            if(_dfs(n, adjList, visited, path, topSort) == false)
                return false;

        path[i] = false;
        topSort.push_back(i);
        return true;
    }

public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto &e : edges)
            adjList[e[0]].push_back(e[1]);

        vector<bool> visited(n, false);
        vector<int> topSort;
        vector<bool> path(n, false);
        for(auto i = 0; i < n; ++i)
            if (_dfs(i, adjList, visited, path, topSort) == false)
                return {};
        reverse(topSort.begin(), topSort.end());
        return topSort;
    }
};
