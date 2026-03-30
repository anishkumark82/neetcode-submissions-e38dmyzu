class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];

        for(auto &n : nums)
        {
            curSum = max(n, curSum + n);
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};
