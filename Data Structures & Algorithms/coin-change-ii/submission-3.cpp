class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto c = 1; c < amount+1; ++c)
            if(coins[0] <= c)
                dp[c] = dp[c-coins[0]];
            
        for(auto r = 1; r < coins.size(); ++r)
            for(auto c = 1; c < amount+1; ++c)
            {
                int skip = dp[c];
                int include = 0;
                if(coins[r] <= c)
                    include = dp[c-coins[r]];
                dp[c] = skip + include;
            }
        return dp.back();
    }
};
