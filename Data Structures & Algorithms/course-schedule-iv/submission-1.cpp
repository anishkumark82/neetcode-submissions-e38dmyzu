
class Solution {
private:
    void _dfs(int i, vector<vector<int>> &adj, unordered_set<int> &visited, vector<unordered_set<int>> &cache)
    {
        if(visited.find(i) != visited.end())
            return; // No cycles expected
        
        visited.insert(i);
        for(auto &n : adj[i])
        {
            _dfs(n, adj, visited, cache);
            // Add n's cache to i's cache
            cache[i].insert(cache[n].begin(), cache[n].end());
            cache[i].insert(n);
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Build an adj list
        vector<vector<int>> adj(numCourses);
        // [0,1] means 1->0
        for(auto &p : prerequisites)
            adj[p[1]].push_back(p[0]);
        
        unordered_set<int> visited;
        // Assertion : no cycles so no need of path variable
        vector<unordered_set<int>> cache(numCourses);
        for(auto i = 0; i < numCourses; ++i)
            _dfs(i, adj, visited, cache);

        vector<bool> out;
        // O(q)
        for(auto q: queries)
        {
            bool result = (cache[q[1]].find(q[0]) != cache[q[1]].end());
            out.push_back(result);
        }
        return out;
    }
};