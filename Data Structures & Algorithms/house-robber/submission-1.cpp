class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> maxVal(nums.size(), 0);
        maxVal[0] = nums[0];
        for(auto i = 1; i < nums.size(); ++i)
        {
            maxVal[i] = max(maxVal[i-1], nums[i]);
            for(auto j = 0; j < i-1; ++j)
                maxVal[i] = max(nums[i]+maxVal[j], maxVal[i]);
        }
        return maxVal.back();
    }
};
