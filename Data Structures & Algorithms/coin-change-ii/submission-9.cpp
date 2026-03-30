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
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return _dfs(0, 0, amount, coins, dp);
    }
};
