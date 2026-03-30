class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Assuming nums.size() != 0
        int curSum = 0;
        int maxSum = nums[0];

        for (auto &n : nums)
        {
            curSum = (curSum < 0) ? n : curSum + n;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
