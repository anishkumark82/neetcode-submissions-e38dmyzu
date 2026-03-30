class Solution {
private:
    int _dfs(int i, int cur, int amount, vector<int>& coins, vector<vector<int>>dp)
    {
        if(i == coins.size())
            return (cur == amount);

        if(cur == amount)
            return 1;

        if(dp[i][cur] != -1)
            return dp[i][cur];

        // 2 Options 
        // 1. Move to next index
        int total = _dfs(i+1, cur, amount, coins, dp);

        // 2. Cointue using the current coin
        if(cur+coins[i] <= amount)
            total += _dfs(i, cur + coins[i], amount, coins, dp);

        dp[i][cur] = total;
        return total;
    }
public:
    int change(int amount, vector<int>& coins) {
        int cur = 0;
        //vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0));
        vector<int> dp(amount+1, 0);
        vector<int> nextDp(amount+1, 0);
        dp[0] = 1;
        nextDp[0] = 1;
        
        for(auto c = 1; c <= amount; ++c)
            if(coins[0] <= c)
                dp[c] = dp[c-coins[0]];
            
        for(auto r = 1; r < coins.size(); ++r)
        {
            for(auto c = 1; c < amount+1; ++c)
            {
                int skip = dp[c];
                int include = 0;
                if(coins[r] <= c)
                    include = nextDp[c-coins[r]];
                nextDp[c] = skip + include;
            }
            dp = nextDp;
        }
        return dp.back();
    }
};
