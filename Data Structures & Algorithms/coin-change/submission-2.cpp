class Solution {
private:

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for(auto c = 1; c<= amount; ++c)
            if(coins[0] <= c)
                dp[c] = 1 + dp[c-coins[0]];
            
        for(auto r = 1; r < coins.size(); ++r)
            for(auto c = 1; c <= amount; ++c)
            {
                int skip = dp[c];
                int include = amount+1;
                if(coins[r]<= c)
                    include = 1 + dp[c-coins[r]];
                dp[c] = min(skip, include);
            }
        int ret = dp.back();
        return (ret > amount) ? -1 : ret;
    }
};
