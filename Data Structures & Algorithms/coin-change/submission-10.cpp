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
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int minCoins = _dfs(0, coins, 0, amount, dp);
        return (minCoins != INT_MAX) ? minCoins : -1;
    }
};
