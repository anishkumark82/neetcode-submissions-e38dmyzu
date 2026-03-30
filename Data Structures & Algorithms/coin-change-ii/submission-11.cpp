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
        //vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        vector<int> dp(amount+1, 0);
        vector<int> newDp(amount+1, 0);
        dp[0] = 1;
        newDp[0] = 1;

        for(auto c = 0; c <= amount; ++c)
            if(c >= coins[0])
                dp[c] = dp[c-coins[0]];
        
        for(auto r = 1; r < coins.size(); ++r)
        {
            for(auto c = 1; c <= amount; ++c)
            {
                // skip
                newDp[c] = dp[c];
                //include
                if(c >= coins[r])
                    newDp[c] += newDp[c-coins[r]];
            } 
            swap(dp, newDp);
        }
        return dp.back();
        //return _dfs(0, 0, amount, coins, dp);
    }
};
