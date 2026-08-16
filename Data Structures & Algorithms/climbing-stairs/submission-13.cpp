class Solution {
// dfs : 2^n
// Memoization : 2^n, Time (O(n)), Space O(n)

private: 
    int _dfs(int n, vector<int> &memo)
    {
        if (n == 0)
            return 1;
        if(n < 0)
            return 0;
        
        if(memo[n] != -1)
            return memo[n];

        // 1 step
        memo[n] = _dfs(n-1, memo) + _dfs(n-2, memo);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        //vector<int> memo(n+1, -1);
        //return _dfs(n, memo);
        if(n <= 1)
            return 1;
        vector<int> dp(2, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(auto i = 2; i < n+1; ++i)
        {
            int tmp = dp[1];
            dp[1] += dp[0];
            dp[0] = tmp;
        }
        return dp[1];
    }
};
