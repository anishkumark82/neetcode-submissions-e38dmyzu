class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];
        for(auto i = 1; i < nums.size(); ++i)
        {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;

    }

    // [    2,  -3, 4,  -2, 2,  1,  -1, 4]
    //      2   -1. 4.  2.  4   5.  4.  8 
    //.     2.  2.  4.  4.  4   5   5.  8
};
