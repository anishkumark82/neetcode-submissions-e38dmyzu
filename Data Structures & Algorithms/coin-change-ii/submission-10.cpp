class Solution {
private:
    int _dfs(int i, int cur, int amount, 
             vector<int> &coins, vector<vector<int>> &dp)
    {
        if(cur == amount)
            return 1;
        
        if(i == coins.size()) // reached unattained path.
            return 0;
        
        if(dp[i][cur] != -1)
            return dp[i][cur];
        
        // skip
        int paths = _dfs(i+1, cur, amount, coins, dp);

        // include
        if(cur + coins[i] <= amount)
            paths += _dfs(i, cur+coins[i], amount, coins, dp);
        dp[i][cur] = paths;        
        return paths;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(auto r = 0; r < coins.size(); ++r)
            dp[r][0] = 1;

        for(auto c = 0; c <= amount; ++c)
            if(c >= coins[0])
                dp[0][c] = dp[0][c-coins[0]];
        
        for(auto r = 1; r < coins.size(); ++r)
            for(auto c = 1; c <= amount; ++c)
            {
                // skip
                dp[r][c] = dp[r-1][c];
                //include
                if(c >= coins[r])
                    dp[r][c] += dp[r][c-coins[r]];
            } 
        return dp.back().back();
        //return _dfs(0, 0, amount, coins, dp);
    }
};
