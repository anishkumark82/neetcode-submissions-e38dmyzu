class Solution {
private:
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> dp(profit.size(), vector<int>(capacity+1, 0));
        // Do the first row
        // profit=[60,100,120]
        // weight=[10,20,30]
        // capacity=50
        for(auto i = 0; i < capacity+1; ++i)
            dp[0][i] = (i-weight[0] >= 0) ? profit[0] : 0; 
        
        for(auto r = 1; r < profit.size(); ++r)
            for(auto c = 0; c < capacity+1; ++c)
            {
                dp[r][c] = dp[r-1][c]; // Dont include the current element
                if(c-weight[r] >= 0)
                    dp[r][c] = max(dp[r][c], profit[r] + dp[r-1][c-weight[r]]);
            }

        return dp.back().back();
    }
};
