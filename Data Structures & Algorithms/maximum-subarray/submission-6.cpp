class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];

        for(auto &n : nums)
        {
            curSum = max(curSum, 0);
            curSum += n;
            curSum = max(curSum, n);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
