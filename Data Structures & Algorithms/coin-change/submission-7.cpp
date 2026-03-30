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
        //vector<vector<int>> dp(coins.size(), vector<int>(amount+1, amount+1));
        vector<int> prev(amount+1, amount+1);
        vector<int> dp(amount+1, amount+1);
        prev[0] = 0;
        dp[0] = 0;
        for(auto c = 0; c < amount+1; ++c)
            if(c >= coins[0])
                prev[c] = 1 + prev[c-coins[0]];
        
        for(auto r = 1; r < coins.size(); ++r)
        {
            for(auto c = 1; c < amount+1; ++c)
            {
                int skip = prev[c];
                int include = amount+1;
                if(c >= coins[r])
                    include = 1 + dp[c-coins[r]];
                dp[c] = min(skip, include);
            }
            swap(prev, dp);
        }
        return (prev.back() < amount+1) ? prev.back() : -1;
    }
};
