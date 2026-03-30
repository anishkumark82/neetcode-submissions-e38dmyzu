class Solution {
private:
    bool _dfs(int i, vector<vector<int>> &adjList, 
              vector<bool> &visited, vector<bool> &path) {
        if(path[i])
            return false;
        
        if(visited[i])
            return true;
        
        visited[i] = true;
        path[i] = true;
        auto &nbrs = adjList[i];
        for(auto &n : nbrs)
            if(_dfs(n, adjList, visited, path) == false)
                return false;

        path[i] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto &e : prerequisites)
            adjList[e[0]].push_back(e[1]);
        
        //vector<int> topSort; // No need to provide the path
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        for(auto i = 0; i < numCourses; ++i)
            if(_dfs(i, adjList, visited, path) == false)
                return false;
        return true;
    }
};
