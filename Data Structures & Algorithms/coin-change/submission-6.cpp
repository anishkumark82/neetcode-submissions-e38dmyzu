class Solution {
    int _dfs(int i, vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 0;

        if(i == coins.size())
            return INT_MAX;

        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        // case where current coin is not considered
        int minCoins = _dfs(i+1, coins, amount, dp);
        if(amount-coins[i] >= 0)
        {
            int temp = _dfs(i, coins, amount-coins[i], dp);
            if(temp != INT_MAX)
                minCoins = min(minCoins, 1 + temp);
        }
        dp[i][amount] = minCoins;
        return minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        // unbound Knapsack problem
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, amount+1));
        
        for(auto r = 0; r < coins.size(); ++r)
            dp[r][0] = 0;

        for(auto c = 0; c < amount+1; ++c)
            if(c >= coins[0])
                dp[0][c] = 1 + dp[0][c-coins[0]];
        
        for(auto r = 1; r < coins.size(); ++r)
            for(auto c = 1; c < amount+1; ++c)
            {
                int skip = dp[r-1][c];
                int include = amount+1;
                if(c >= coins[r])
                    include = 1 + dp[r][c-coins[r]];
                dp[r][c] = min(skip, include);
            }
        return (dp.back().back() < amount+1) ? dp.back().back() : -1;
    }
};
