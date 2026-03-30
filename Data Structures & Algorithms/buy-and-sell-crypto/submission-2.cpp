class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(auto i = 1; i < prices.size(); ++i)
        {
            // If sell at i
            int curProfit = (minPrice >= prices[i]) ? 0 : (prices[i] - minPrice);
            maxProfit =  max(curProfit, maxProfit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
