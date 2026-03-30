class Solution {
public:
    vector<int> countBits(int n) {
        // 0 --> 0000
        // 1 --> 0001 --> 1 --> 2^0
        // 2 --> 0010 --> 1 1 --> 2^ 1 
        // 3 --> 0011 --> 2 1 + dp[3-2]
        // 4 --> 0100 --> 1 --> 2^2 [dp 4-2]
        // 5 --> 0101 --> 2  1 + dp[5-4]
        // 6 --> 0110 --> 2  1 + dp[6-4]
        // 7 --> 0111 --> 3  1 + dp[7-4]
        // 8 --> 1000 --> 1 --> 2^3
        if(n == 0)
            return {0};

        int pow = 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(auto i = 2; i <= n; ++i)
        {
            pow = (i == pow * 2) ? pow * 2 : pow;
            dp[i] = (i == pow) ? 1 : 1 + dp[i-pow];
        } 
        return dp;
    }
};
