class Solution {
private:
    bool _dfs(int i, vector<vector<int>> &adj, unordered_set<int> &visited, unordered_set<int> &path)
    {
        if(path.find(i) != path.end())
            return false;

        if(visited.find(i) != visited.end())
            return true;

        visited.insert(i);
        path.insert(i);
        
        for(auto &n : adj[i])
            if(!_dfs(n, adj, visited, path))
                return false;

        path.erase(i);
        return true;        
    } 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites)
            adj[p[0]].push_back(p[1]);
        
        unordered_set<int> visited;
        unordered_set<int> path;

        // vector<int> sorted; // As long as there is no cycle we can finish
        for(auto i = 0; i < adj.size(); ++i)
            if(!_dfs(i, adj, visited, path))
                return false;

        return true;        

    }
};
