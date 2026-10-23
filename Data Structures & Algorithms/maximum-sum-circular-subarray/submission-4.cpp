class Solution { 
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int curMaxSum = 0;
        int globalMaxSum = nums[0];
        int curMinSum = 0;
        int globalMinSum = nums[0];

        for(auto &n : nums)
        {
            curMaxSum = max(curMaxSum+n, n);
            globalMaxSum = max(curMaxSum, globalMaxSum);

            curMinSum = min(curMinSum+n, n);
            globalMinSum = min(curMinSum, globalMinSum);

            totalSum += n;            
        }

        return (globalMaxSum > 0) ? max(globalMaxSum, totalSum-globalMinSum): globalMaxSum;
    }
};