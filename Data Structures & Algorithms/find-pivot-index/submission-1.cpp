class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Start with postfix sum
        // then with prefix sum

        vector<int> rSum(nums.size(), 0);
        for(int i = nums.size()-2; i >=0; --i)
            rSum[i] = rSum[i+1] + nums[i+1];
        
        int lSum = 0;
        for(auto i = 0; i < nums.size(); ++i)
        {
            lSum = (i == 0) ? 0 : lSum + nums[i-1];
            if(lSum == rSum[i])
                return i;
        }
        return -1;
    }
};