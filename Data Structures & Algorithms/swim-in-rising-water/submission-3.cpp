class Solution {
private:
    // [0 1]
    // [2 3]

    void _dfs(vector<vector<int>> &grid, int r, int c, int curTime, int &minTime, vector<vector<bool>> &visited)
    {
        int rMax = grid.size();
        int cMax = grid[0].size();
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;

        if(!rInBounds || !cInBounds)
            return;
        
        
        // for degrees of freedom
        if(visited[r][c])
            return;
        
        visited[r][c] = true;
        int incrVal = (curTime >= grid[r][c]) ? 0 : grid[r][c]-curTime;
        curTime += incrVal;
        if(r == rMax-1 && c == cMax-1)
            minTime = min(minTime, curTime);
        else
        {
            _dfs(grid, r+1, c, curTime, minTime, visited);
            _dfs(grid, r-1, c, curTime, minTime, visited);
            _dfs(grid, r, c+1, curTime, minTime, visited);
            _dfs(grid, r, c-1, curTime, minTime, visited);
        }
        visited[r][c] = false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int curTime = 0;
        int minTime = INT_MAX;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        _dfs(grid, 0, 0, curTime, minTime, visited);
        return minTime;
    }
};
