class Solution {
    // dfs -- 2^mn, O(m+n)
    // Memoization - O(mn), O(m+n)
private:
    int _dfs(int r, int c, int rMax, int cMax, vector<vector<int>> &memo)
    {
        if(r > rMax-1 || c > cMax-1)
            return 0;

        if(r == rMax-1 && c == cMax-1)
            return 1;

        if(memo[r][c] != -1)
            return memo[r][c];

        memo[r][c] = _dfs(r+1, c, rMax, cMax, memo) + _dfs(r, c+1, rMax, cMax, memo);
        return memo[r][c];
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return _dfs(0, 0, m, n, memo);

        vector<vector<int>> dp(m+1, vector<int>(n, 0));
        for(auto r = 0; r <= m; ++r)
            dp[r][0] = 1;

        for(auto r = 1; r <= m; ++r)
            for(auto c = 1; c < n; ++c)
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
        
        return dp.back().back();

    }
};
