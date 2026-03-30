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
        vector<vector<int>> dp(rMax, vector<int>(cMax, -1));
        return _dfs(obstacleGrid, 0, 0, dp);
    }
    int rMax;
    int cMax;
};