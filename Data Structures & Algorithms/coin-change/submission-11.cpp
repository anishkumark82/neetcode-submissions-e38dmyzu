class Solution {
private:

    int _dfs(int i, vector<int>& coins, int cur, int amount, vector<vector<int>> &dp)
    {
        if(cur == amount)
            return 0;
        
        if(i == coins.size())
            return INT_MAX;

        if(dp[i][cur] != -1)
            return dp[i][cur];

        // Skip
        int minCoins = _dfs(i+1, coins, cur, amount, dp);

        // Include
        if(cur <= amount - coins[i])
        {
            int temp = _dfs(i, coins, cur+coins[i], amount, dp);
            if(temp != INT_MAX)
                minCoins = min(minCoins, temp+1);
        }
        dp[i][cur] = minCoins;
        return minCoins;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, amount+1));
        for(auto r = 0; r < coins.size(); ++r)
            dp[r][0] = 0;
        
        for(auto c = 1; c < amount+1; ++c)
            if(coins[0] <= c)
                dp[0][c] = 1 + dp[0][c-coins[0]];

        for(int r = 1; r < coins.size(); ++r)
            for(int c = 1; c <= amount; ++c)
            {
                // skip 
                int skip = dp[r-1][c];
                int include = amount+1;
                if(coins[r] <= c)
                    include = 1 + dp[r][c-coins[r]];
                
                dp[r][c] = min(include, skip);
            } 
        int result = dp.back().back();
        return (result > amount) ? -1 : result;
    }
};
