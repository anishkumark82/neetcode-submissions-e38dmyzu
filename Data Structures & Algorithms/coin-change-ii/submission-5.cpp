class Solution {
private:
    int _dfs(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 1;
        if(amount < 0)
            return 0;

        if (i == coins.size())
            return 0;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];

        // skip current coin
        int path = _dfs(i+1, amount, coins, dp);

        // include current coin
        path += _dfs(i, amount-coins[i], coins, dp);
        dp[i][amount] = path;
        return path;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return _dfs(0, amount, coins, dp);
    }
};
