class Solution {
    bool _dfs(int i, vector<int> &topSort, unordered_set<int> &path)
    {
        if(path.find(i) != path.end())
            return false;
        if(visited[i] == true)
            return true;
        
        visited[i] = true;
        path.insert(i);
        vector<int> &nbrs = adjList[i];
        for(auto &nbr : nbrs)
            if(_dfs(nbr, topSort, path) != true)
                return false;

        topSort.push_back(i);
        path.erase(i);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // a,b edge --> b has to be done before a
        // post order traversal should get us the data.
        numSize = numCourses;
        adjList.resize(numCourses);
        for(auto &p : prerequisites)
            adjList[p[0]].push_back(p[1]);

        vector<int> topSort;
        visited.resize(numSize, false);
        unordered_set<int> path;

        for(auto i = 0; i < numCourses; ++i)
            if(_dfs(i, topSort, path) != true)
                return false;
        return true;
    }
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    int numSize;
};
