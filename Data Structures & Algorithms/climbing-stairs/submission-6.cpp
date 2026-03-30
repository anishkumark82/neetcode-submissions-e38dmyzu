class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(2, 1);
        for(auto i = 2; i < n+1; ++i)
        {
            int tmp = dp[1];
            dp[1] += dp[0];
            dp[0] = tmp;
        }
        return dp[1];
    }
};
