class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        vector<int> dp(amount+1, 0);
        //for(auto r = 0; r < coins.size(); ++r)
        //    dp[r][0] = 1;
        dp[0] = 1;
        for(auto c = 1; c < amount+1; ++c)
            if(coins[0] <= c)
            {
                //dp[0][c] = dp[0][c-coins[0]];
                dp[c] = dp[c-coins[0]];
            }
            
        for(auto r = 1; r < coins.size(); ++r)
            for(auto c = 1; c < amount+1; ++c)
            {
                //int skip = dp[r-1][c];
                int skip = dp[c];
                int include = 0;
                if(coins[r] <= c)
                {
                    //include = dp[r][c-coins[r]];
                    include = dp[c-coins[r]];
                }
                //dp[r][c] = skip + include;
                dp[c] = skip + include;
            }
        //return dp.back().back();
        return dp.back();
    }
};
