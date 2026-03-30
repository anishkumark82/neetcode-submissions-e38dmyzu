class Solution {
    int _dfs(int i, vector<int>& coins, int amount)
    {
        if(amount == 0)
            return 0;

        if(i == coins.size())
            return INT_MAX;
        
        // case where current coin is not considered
        int minCoins = _dfs(i+1, coins, amount);
        if(amount-coins[i] >= 0)
        {
            int temp = _dfs(i, coins, amount-coins[i]);
            if(temp != INT_MAX)
                minCoins = min(minCoins, 1 + temp);
        }
        return minCoins;    
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // unbound Knapsack problem
        int minCoins = _dfs(0, coins, amount);  
        return (minCoins != INT_MAX) ? minCoins : -1;
    }
};
