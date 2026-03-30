class Solution {
private:
    int _dfs(int i, vector<vector<int>> &adj, unordered_set<int> &visited, unordered_set<int> &path)
    {
        if(path.find(i) != path.end()) // detected a cycle
            return false;
        
        if(visited.find(i) != visited.end())
            return true;

        visited.insert(i);
        path.insert(i);

        for(auto &n : adj[i])
            if(_dfs(n, adj, visited, path) == false)
                return false;

        path.erase(i);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct adj List
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites)
            adj[p[0]].push_back(p[1]);
        
        unordered_set<int> visited; // Track wheter we visited all the nodes
        unordered_set<int> path; // cycle detection
        //vector<int> tSort; // Can be avoided since this is not asked

        for(auto i = 0; i < adj.size(); ++i)
            if(_dfs(i, adj, visited, path) == false)
                return false;
        return true;
    }
};
