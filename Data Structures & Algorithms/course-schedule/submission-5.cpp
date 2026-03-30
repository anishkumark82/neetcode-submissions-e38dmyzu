class Solution {
public:
    bool _dfs(int n, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        if(visited[n]) // detected a cycle
            return false;
        
        visited[n] = true;
        for(auto &nb : adjList[n])
            if(_dfs(nb, adjList, visited) == false)
                return false;
        visited[n] = false;    
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for(auto &p : prerequisites)
            adjList[p[0]].push_back(p[1]);

        vector<bool>visited(numCourses, false);
        for(auto n = 0; n < numCourses; ++n)
            if(_dfs(n, adjList, visited) == false)
                return false;
        return true;
    }
};
