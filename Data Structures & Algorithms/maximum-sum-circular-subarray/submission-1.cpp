class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Track the maxSum and minSum

        int maxVal = *max_element(nums.begin(), nums.end());
        if (maxVal < 0)
            return maxVal;

        int curMaxSum = 0;
        int maxSum = nums[0];
        int curMinSum = 0;
        int minSum = nums[0];
        int total = 0;

        for(auto &n: nums)
        {
            curMaxSum = max(curMaxSum+n, n);
            maxSum = max(maxSum, curMaxSum);
            curMinSum = min(curMinSum+n, n);
            minSum = min(minSum, curMinSum);
            total += n;
        }
        return max(maxSum, total-minSum);
    }
};