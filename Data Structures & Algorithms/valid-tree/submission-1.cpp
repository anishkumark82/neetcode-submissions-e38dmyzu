class Solution {
private:
    bool _dfs(int i, int p, vector<vector<int>> &adj, unordered_set<int> &visited)
    {
        if(visited.find(i) != visited.end())
            return false;

        visited.insert(i);
        for(auto &n : adj[i])
            if(n != p && !_dfs(n, i, adj, visited))
                return false;
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // create adjList
        vector<vector<int>> adj(n);
        for(auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int>visited;
        if (!_dfs(0, -1, adj, visited))
            return false;

        return visited.size() == n;
    }
};
