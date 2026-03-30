class Solution {
private: 
    bool _dfs(int i, vector<bool> &visited)
    {
        if(visited[i]) // detected a cycle
            return false;
        
        visited[i] = true;
        for(auto j = 0; j < mAdj[i].size(); ++j)
            if(_dfs(mAdj[i][j], visited) == false)
                return false;
        
        mAdj[i].clear();
        visited[i] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // do a dfs 
        // if cycle it is not doable
        // all the nodes must be visitable.
        mAdj.resize(numCourses);
        vector<bool>visited(numCourses, false);        
        for(auto &p : prerequisites)
            mAdj[p[0]].push_back(p[1]); 
        
        for(auto i = 0; i < mAdj.size(); ++i)
            if(_dfs(i, visited) == false)
                return false;
        return true;        
    }
private:
    vector<vector<int>>mAdj;
};
