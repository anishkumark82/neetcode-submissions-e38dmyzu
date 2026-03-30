class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // [2, -3, 4, -2, 2, 1, -1, 4]
        // [2, -1, 4, 2, 4,  5, 4,  8]

        // Applying kadane's algorithm
        int curSum = nums[0];
        int maxVal = nums[0];
        
        for(auto i = 1; i < nums.size(); ++i)
        {
            curSum = (nums[i] > curSum + nums[i])? nums[i] : curSum + nums[i];
            maxVal = max(curSum, maxVal);
        }
        return maxVal;
    }
};
