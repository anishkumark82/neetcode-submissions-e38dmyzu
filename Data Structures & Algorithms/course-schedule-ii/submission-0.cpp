class Solution {
private:
    bool _dfs(int i, vector<int> &topSort, unordered_set<int> &path)
    {
        if(path.find(i) != path.end())
            return false;
        
        if(visited[i])
            return true;
        
        visited[i] = true;
        path.insert(i);

        vector<int> &nbrs = adjList[i];
        for(auto &nbr : nbrs)
            if(_dfs(nbr, topSort, path) == false)
                return false;
        topSort.push_back(i);
        path.erase(i);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjList.resize(numCourses);
        for(auto &p : prerequisites)
            adjList[p[0]].push_back(p[1]);

        n = numCourses;
        visited.resize(n);
        vector<int> topSort;
        unordered_set<int> path;

        for(auto i = 0; i < n; ++i)
            if(_dfs(i, topSort, path) != true)
                return {};
        
        return topSort;
    }
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    int n;
};
