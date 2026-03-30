class Solution {
private:
    int _dfs(int i, vector<int> &p, vector<int>& w, int c, vector<vector<int>> &dp)
    {
        if(i == p.size())
            return 0;
        
        if(dp[i][c] != -1)
            return dp[i][c];

        // Skip current
        int maxP = _dfs(i+1, p, w, c, dp);

        // include
        if(c-w[i] >= 0)
            maxP = max(maxP, p[i] + _dfs(i, p, w, c-w[i], dp));

        dp[i][c] = maxP;        
        return maxP;
    }
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> dp(profit.size(), vector<int>(capacity+1, -1));
        return _dfs(0, profit, weight, capacity, dp);
    }
};
