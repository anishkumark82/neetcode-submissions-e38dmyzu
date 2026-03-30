class Solution {
private:
/*
    int _dfs(int i, vector<int>& coins, int cur, int amount)
    {
        if(cur == amount)
            return 0;
        
        if(i == coins.size())
            return 1e9;

        // Skip
        int minCoins = _dfs(i+1, coins, cur, amount);

        // Include
        if(cur+coins[i] <= amount)
        {
            int temp = _dfs(i, coins, cur+coins[i], amount);
            if(temp != 1e9)
                minCoins = min(minCoins, temp+1);
        }
        return minCoins;
    }
*/

int _dfs(int i, vector<int> &coins, int cur, int amount)
{
    if(cur == amount)
        return 0;
    
    if(i == coins.size())
        return INT_MAX;
    
    // Skip
    int minCoins = _dfs(i+1, coins, cur, amount);

    //include
    if(cur + coins[i] <= amount)
    {
        int temp = _dfs(i, coins, cur+coins[i], amount);
        if(temp != INT_MAX)
            minCoins = min(minCoins, 1+temp);
    }
    return minCoins;    
}

public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = _dfs(0, coins, 0, amount);
        return (minCoins != INT_MAX) ? minCoins : -1;
    }
};
