class Solution {
private:
    bool _dfs(int i, vector<vector<int>> &adj, unordered_set<int> &visited, 
              unordered_set<int> &path, vector<int> &tSort)
    {
        if(path.find(i) != path.end())
            return false;
        
        if(visited.find(i) != visited.end())
            return true;
        
        visited.insert(i);
        path.insert(i);

        for(auto &n : adj[i])
            if(!_dfs(n, adj, visited, path, tSort))
                return false;
        path.erase(i); // Remove for newer paths.
        tSort.push_back(i);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites)
            adj[p[0]].push_back(p[1]);
        
        unordered_set<int> visited;
        unordered_set<int> path;
        vector<int> tSort;

        for (auto i = 0; i < numCourses; ++i)
            if (!_dfs(i, adj, visited, path, tSort))
                return {};
        return tSort;
    }
};
