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
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int minCoins = _dfs(0, coins, amount, dp);
        return (minCoins != INT_MAX) ? minCoins : -1;
    }
};
