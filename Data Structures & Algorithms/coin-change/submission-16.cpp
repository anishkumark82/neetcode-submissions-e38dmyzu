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
        vector<int> dp(amount+1, amount+1); 
        vector<int> newDp(amount+1, amount+1); 
        dp[0] = 0;
        newDp[0] = 0;

        for(auto c = 1; c < amount+1; ++c)
            if(coins[0] <= c)
                dp[c] = 1 + dp[c-coins[0]];

        for(auto r = 1; r < coins.size(); ++r)
        {
            for(auto c = 1; c <= amount; ++c)
            {
                // skip
                newDp[c] = dp[c];
                // include
                if(coins[r] <= c)
                    newDp[c] = min(newDp[c], 1 + newDp[c-coins[r]]);
            }
            dp = newDp;
        }
        return dp.back() <= amount ? dp.back() : -1;
    }
};
