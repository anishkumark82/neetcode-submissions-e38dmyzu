class Solution {
private:

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, amount+1));

        for(auto r = 0; r < coins.size(); ++r)
            dp[r][0] = 0;
        
        for(auto c = 1; c<= amount; ++c)
            if(coins[0] <= c)
                dp[0][c] = 1 + dp[0][c-coins[0]];
            
        for(auto r = 1; r < coins.size(); ++r)
            for(auto c = 1; c <= amount; ++c)
            {
                int skip = dp[r-1][c];
                int include = amount+1;
                if(coins[r]<= c)
                    include = 1 + dp[r][c-coins[r]];
                dp[r][c] = min(skip, include);
            }
        int ret = dp.back().back();
        return (ret > amount) ? -1 : ret;
    }
};
