class Solution {
private:
    int _dfs(int i, vector<int> &coins, int amount)
    {
        if(amount == 0)
            return 0;
        if(i == coins.size())
            return INT_MAX;
        
        int minCoins = _dfs(i+1, coins, amount);
        if(amount - coins[i] >= 0)
        {
            int curCoins = _dfs(i, coins, amount-coins[i]);
            if(curCoins != INT_MAX)
                curCoins++;
            minCoins = min(minCoins, curCoins);
        } 
        return minCoins;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = _dfs(0, coins, amount);
        return (minCoins != INT_MAX) ? minCoins : -1;
    }
};
