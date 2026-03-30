class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rMax = obstacleGrid.size();
        cMax = obstacleGrid[0].size();
        if(obstacleGrid[0][0] != 0 || obstacleGrid[rMax-1][cMax-1] != 0)
            return 0;
        
        vector<int> dp(cMax, 0);
        vector<int> newDp(cMax, 0);
        newDp[cMax-1] = 1;
        
        for(int r = rMax-1; r >= 0; r--)
        {
            for(int c = cMax-1; c >= 0; c--)
            {
                if(r == rMax-1 && c == cMax-1)
                    continue;

                if(obstacleGrid[r][c] == 1)
                    newDp[c] = 0;
                else
                {
                    newDp[c] = dp[c];
                    if(c+1 < cMax)
                        newDp[c] += newDp[c+1];
                }
            }
            dp = newDp;
        }
        return dp[0];
    }

    int rMax;
    int cMax;
};