class Solution {
private:
    int _dfs(int i, vector<int> &coins, int cur, int amount, vector<vector<int>> &dp)
    {
        if(cur == amount)
            return 0;
        if(i == coins.size())
            return amount+1;

        if(dp[i][cur] != -1)
            return dp[i][cur];

        // skip
        int minCoins = _dfs(i+1, coins, cur, amount, dp);

        // include
        if(coins[i] <= amount)
        {
            int newCur = cur + coins[i];
            if(newCur <= amount)
                minCoins = min(minCoins, 1 + _dfs(i, coins, newCur, amount, dp));
        }

        dp[i][cur] = minCoins; 
        return minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        int minCoins =  _dfs(0, coins, 0, amount, dp);
        return minCoins > amount ? -1 : minCoins;
    }
};
