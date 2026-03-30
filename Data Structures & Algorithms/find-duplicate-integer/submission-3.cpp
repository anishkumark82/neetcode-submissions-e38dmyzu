class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto i = 0; i < nums.size(); ++i)
        {
            int idx = abs(nums[i]);
            if(nums[idx] < 0)
                return abs(nums[i]);
            nums[idx] = -1 * nums[idx];
        }
        return -1;
    }
};
