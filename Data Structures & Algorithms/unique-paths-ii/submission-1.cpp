class Solution {
public:
    int _dfs(vector<vector<int>>& obGrid, int r, int c, vector<vector<int>> &dp)
    {
        if(r > rMax-1 || c > cMax-1)
            return 0;
        
        if(obGrid[r][c] == 1)
            return 0;
        
        if(dp[r][c] != -1)
            return dp[r][c];

        if(r == rMax-1 && c == cMax-1) // Reached the bottom right corner
            return 1;
                
        dp[r][c] = _dfs(obGrid, r+1, c, dp) + _dfs(obGrid, r, c+1, dp);
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rMax = obstacleGrid.size();
        cMax = obstacleGrid[0].size();
        if(obstacleGrid[0][0] != 0 || obstacleGrid[rMax-1][cMax-1] != 0)
            return 0;
        
        vector<vector<int>> dp(rMax, vector<int>(cMax, 0));
        dp[rMax-1][cMax-1] = 1;
        for(int r = rMax-1; r >= 0; r--)
            for(int c = cMax-1; c >= 0; c--)
            {
                if(obstacleGrid[r][c] == 1)
                    continue;
                if(r+1 < rMax) // no need for the check of obs[r+1][c] since dp[r+1][c] is zero if obs[r+1][c] is zero.
                    dp[r][c] = dp[r+1][c];
                if(c+1 < cMax) // no need for the check of obs[r][c+1] since dp[r][c+1] is zero if obs[r][c+1] is zero.
                    dp[r][c] += dp[r][c+1];
            }
        return dp[0][0];
    }
    int rMax;
    int cMax;
};