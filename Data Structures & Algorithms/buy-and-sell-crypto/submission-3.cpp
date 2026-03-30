class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        int curProfit = 0;

        for(auto &p : prices)
        {
            curProfit = p - minPrice;
            curProfit = max(0, p-minPrice);
            minPrice = min(minPrice, p);
            maxProfit = max(maxProfit, curProfit);
        }
        return maxProfit;
    }
};
