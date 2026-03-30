class Solution {
private:
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
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        // u comes before v in the ordering
        // Cycle detection is also needed
        nSize = n;
        adjList.resize(n);

        for(auto &e : edges)
            adjList[e[0]].push_back(e[1]);

        visited.resize(n, false);
        vector<int> topSort;
        unordered_set<int>path;
        for(auto i = 0; i < n; ++i)    
            if(_dfs(i, topSort, path) != true)
                return {};
        
        reverse(topSort.begin(), topSort.end());
        return topSort;
    }
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    int nSize;
};
