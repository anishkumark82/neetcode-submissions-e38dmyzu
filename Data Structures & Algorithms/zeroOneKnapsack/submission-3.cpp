class Solution {
private:
    // O(n*m) solution
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        // Using Bottom up approach or Tabulaiton method
        // Create a matrix with capacity columns and profit.size() rows.
        vector<vector<int>> dp(weight.size(), vector<int>(capacity+1, 0));

        // first column will be zero since the max profit with capacity zero is 0.
        // populate first row
        for(auto c = 0; c < capacity; ++c)
            if (weight[0] <= c) 
                dp[0][c] = profit[0];

        for(auto r = 1; r < weight.size(); ++r)
            for(auto c = 1; c < capacity+1; ++c)
            {
                // assuming current idx value is skipped
                int skip = dp[r-1][c];
                //check if the current idx weight is <= c (current capacity)
                int include = 0;
                if(weight[r] <= c)
                {
                    // also include max profit of c - weight[r]  if c = 5 & wt[r] = 4 then include profit[r] + dp[r-1][5-4]
                    include = profit[r] + dp[r-1][c-weight[r]];
                }
                dp[r][c] = max(skip, include);
            }
        return dp.back().back();
    }
};
