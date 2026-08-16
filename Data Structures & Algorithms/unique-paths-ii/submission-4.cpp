class Solution {
public:
    int _dfs(vector<vector<int>> &g, int r, int c, int rMax, int cMax, vector<vector<int>> &dp)
    {
        if(r >= rMax || c >= cMax)
            return 0;
        
        if(r == rMax-1 && c == cMax-1)
            return 1;
        
        if(g[r][c] != 0)
            return 0;
        
        if(dp[r][c] != -1)
            return dp[r][c];

        dp[r][c] = _dfs(g, r+1, c, rMax, cMax, dp) + _dfs(g, r, c+1, rMax, cMax, dp);
        return dp[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rMax = obstacleGrid.size();
        int cMax = obstacleGrid[0].size();
        vector<vector<int>> dp(rMax, vector<int>(cMax, -1));      
        if(obstacleGrid[0][0] != 0 || obstacleGrid[rMax-1][cMax-1] != 0)
            return 0;

        return _dfs(obstacleGrid, 0,0,rMax, cMax, dp);
    }
};