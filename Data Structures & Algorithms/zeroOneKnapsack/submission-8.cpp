class Solution {
private:
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<int> dp(capacity+1, 0);
        vector<int> newDp(capacity+1, 0);

        for(auto i = 0; i < capacity+1; ++i)
            dp[i] = (i-weight[0] >= 0) ? profit[0] : 0; 
        
        for(auto r = 1; r < profit.size(); ++r)
        {
            for(auto c = 0; c < capacity+1; ++c)
            {
                newDp[c] = dp[c]; // Dont include the current element
                if(c-weight[r] >= 0)
                    newDp[c] = max(newDp[c], profit[r] + dp[c-weight[r]]);
            }
            dp = newDp;
        }
        return dp.back();
    }
};
