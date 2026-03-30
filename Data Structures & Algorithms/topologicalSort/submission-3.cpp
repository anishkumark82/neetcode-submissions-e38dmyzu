class Solution {
private:
    bool _dfs(int i, vector<vector<int>> &adj, 
              unordered_set<int> &visited, 
              unordered_set<int> &path, vector<int> &ts)
    {
        if(path.find(i) != path.end())
            return false;
        
        if(visited.find(i) != visited.end())
            return true;
        
        visited.insert(i);
        path.insert(i);

        for(auto &n : adj[i])
            if(!_dfs(n, adj, visited, path, ts))
                return false;
        
        path.erase(i);
        ts.push_back(i);
        return true;
    }
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        
        // Create an adj List
        vector<vector<int>> adj(n);
        for(auto &e: edges)
            adj[e[0]].push_back(e[1]);

        // Visited Set
        unordered_set<int> visited;
        // Path Set to detect cycle
        unordered_set<int> path;

        // Return data
        vector<int> sorted;

        // Perform DFS on the graph for each node (there could be mulitple connected graphs)
        for(auto i = 0; i < n; ++i)
            if(!_dfs(i, adj, visited, path, sorted))
                return {};
        
        // reverse the sorted list and return
        reverse(sorted.begin(), sorted.end());
        return sorted;
    }
};
