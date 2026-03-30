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
        vector<int> newDp(n, 0);
        vector<int> dp (n, 0);
        
        for(int r = m-1; r >= 0; r--)
        {
            newDp[n-1] = 1;
            for(int c = n-2; c >= 0; c--)
            {
                newDp[c] = dp[c];
                newDp[c] += newDp[c+1];
            }
            dp = newDp;
        }
        return newDp[0];
    }
};
