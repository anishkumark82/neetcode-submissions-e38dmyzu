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
        if(obstacleGrid[0][0] != 0 || obstacleGrid[rMax-1][cMax-1] != 0)
            return 0;

        //vector<vector<int>> dp(rMax, vector<int>(cMax, -1));      
        //return _dfs(obstacleGrid, 0,0,rMax, cMax, dp);
        //vector<vector<int>> dp(rMax+1, vector<int>(cMax, 0));
        vector<int> dp(cMax, 0);
        dp[0] = 1;
        
        for(auto r = 1; r <= rMax; ++r)
        {
            vector<int> newDp(cMax, 0);
            newDp[0] = (obstacleGrid[r-1][0] == 0) ? dp[0] : 0;
        
            for(auto c = 1; c < cMax; ++c)
            {
                if(obstacleGrid[r-1][c] != 0)
                    continue;
                newDp[c] = dp[c] + newDp[c-1];
            }
            swap(newDp, dp);
        }
        return dp.back();
    }
};