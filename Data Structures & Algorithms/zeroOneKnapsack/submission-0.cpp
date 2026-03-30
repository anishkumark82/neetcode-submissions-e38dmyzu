class Solution {
private:
    int _dfs(int i, vector<int> &profit, vector<int>& weight, int capacity)
    {
        if(i == profit.size())
            return 0;
        
        int maxProfit = 0;
        // Path with current index included
        if(weight[i] <= capacity)
        {
             maxProfit = profit[i];
             maxProfit += _dfs(i+1, profit, weight, capacity-weight[i]);
        }
        // Path without including the current index
        maxProfit = max(maxProfit, _dfs(i+1, profit, weight, capacity));
        return maxProfit;
    }
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        return _dfs(0, profit, weight, capacity);        
    }
};
