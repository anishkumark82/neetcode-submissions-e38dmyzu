class Solution {
private:
    // Brute Force - Time O(2^c) where c > n - Space - O(c)
    // Memoization - Time - O(c) * cap Space - O(c * cap)
    //
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
        //vector<vector<int>> dp(profit.size(), vector<int>(capacity+1, 0));
        vector<int> dp(capacity+1, 0);
        vector<int> newDp(capacity+1, 0);
        //return _dfs(0, profit, weight, capacity, dp);
        for(auto c = 0; c < dp.size(); ++c)
            if(weight[0] <= c)
                dp[c] = profit[0] + dp[c-weight[0]];
            
        for (auto r = 1; r < profit.size(); ++r)
        {
            for(auto c = 0; c < dp.size(); ++c)
            {
                int skip = dp[c];
                int include = 0;
                if(weight[r] <= c)
                    include = profit[r]+newDp[c-weight[r]];
                newDp[c] = max(skip, include);
            }
            swap(newDp, dp);
        }
        return dp.back();
    }
};
