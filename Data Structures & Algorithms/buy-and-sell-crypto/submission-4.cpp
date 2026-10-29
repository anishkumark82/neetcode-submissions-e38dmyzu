class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 7, 1, 5, 3, 6, 4
        //       p 
        // curMin = 1
        // profit = 0
        // maxProfit = 0
        int curMin = prices[0];
        int maxProfit = 0;
        for(auto &p : prices)
        {
            int profit = (p > curMin) ? p - curMin : 0;
            maxProfit = max(profit, maxProfit);
            curMin = min(curMin, p);
        }
        return maxProfit;
    }
};
