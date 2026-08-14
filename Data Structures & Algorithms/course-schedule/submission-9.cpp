class Solution {
private:
    bool _dfs(int i, vector<unordered_set<int>> &preq, unordered_set<int> &visited)
    {
        if(visited.count(i))
            return false;
        
        if(preq[i].empty()) // no dependencies
            return true;

        visited.insert(i);
        for(auto itr = preq[i].begin(); itr != preq[i].end();)
        {
            if(!_dfs(*itr, preq, visited))
                return false;
            itr = preq[i].erase(itr);
        }
        visited.erase(i);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> preq(numCourses);
        for(auto &p : prerequisites)
            preq[p[0]].insert(p[1]);
        
        for(auto i = 0; i < numCourses; ++i)
        {
            // loop detection
            unordered_set<int> visited;
            if(!_dfs(i, preq, visited)) // check if loop
                return false;
        }
        return true;
    }

};
