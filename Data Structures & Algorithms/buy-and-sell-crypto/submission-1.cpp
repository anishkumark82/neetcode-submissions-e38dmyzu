class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>minPrice(prices.size(), 0);
        vector<int>maxProfit(prices.size(), 0);

        minPrice[0] = prices[0]; // 5, 1, 1,  
        maxProfit[0] = 0; // 0, 0, 4, 5, 6, 1

        for(auto i = 1; i < prices.size(); ++i)
        {
            // If sell at i
            int curProfit = (minPrice[i-1] >= prices[i]) ? 0 : (prices[i] - minPrice[i-1]);
            maxProfit[i] =  max(curProfit, maxProfit[i-1]);
            minPrice[i] = min(minPrice[i-1], prices[i]);
        }
        return maxProfit.back();
    }
};
