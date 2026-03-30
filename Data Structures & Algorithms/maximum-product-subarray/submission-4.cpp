class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1;
        int curMin = 1;
        int maxProd = INT_MIN;

        for(auto &n : nums)
        {
            int pMax = curMax*n;
            int pMin = curMin*n; // Assume both are negative

            curMax = max(max(n, pMax), pMin);
            curMin = min(min(n, pMax), pMin);
            maxProd = max(maxProd, curMax);
        }
        return maxProd;
    }
};
