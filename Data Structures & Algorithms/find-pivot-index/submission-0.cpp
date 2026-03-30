class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> lSum(nums.size(), 0);

        for(auto i = 1; i < nums.size(); ++i)
            lSum[i] = nums[i-1] + lSum[i-1];

        int result = -1;
        int rSum = 0;
        for(int i = nums.size()-2; i >= 0;--i)
        {
            rSum = nums[i+1] + rSum;
            if(rSum == lSum[i])
                result = i;
        }

        // handling a corner case
        if(result == -1 && lSum[nums.size()-1] == 0)
            result = nums.size()-1;
        
        return result;
    }
};