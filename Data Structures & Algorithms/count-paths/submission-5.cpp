class Solution {
    int _dfs(int r, int c, int rMax, int cMax, vector<vector<int>> &memo)
    {
        if (r > rMax || c > cMax)
            return 0;
        if(r == rMax && c == cMax) // Reached the destination
            return 1;
        if(memo[r][c] != -1)
            return memo[r][c];
        memo[r][c] = _dfs(r+1, c, rMax, cMax, memo) + _dfs(r, c+1, rMax, cMax, memo);
        return memo[r][c];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;

        for(int r = m-1; r >= 0; r--)
            for(int c = n-1; c >= 0; c--)
            {
                if (r+1 < m)
                    dp[r][c] = dp[r+1][c];
                if (c+1 < n)
                    dp[r][c] += dp[r][c+1];
            }
        return dp[0][0];
    }
};
