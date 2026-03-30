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
        vector<int> dp(amount+1, 0);
        vector<int> newDp(amount+1, 0);
        dp[0] = 1;
        newDp[0] = 1;

        for(auto c = 1; c < amount+1; ++c)
            if(coins[0] <= c)
                dp[c] = dp[c-coins[0]];

        for(auto r = 1; r < coins.size(); ++r)
        {
            for(auto c = 1; c <= amount; ++c)
            {
                int skip = dp[c];
                int include = 0;
                if(coins[r] <= c)
                    include = newDp[c-coins[r]];
                newDp[c] = skip + include;
            }
            swap(dp, newDp);
        }
        return dp.back();
    }
};
