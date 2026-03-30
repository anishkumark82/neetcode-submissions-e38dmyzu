class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        int rob1 = nums[0];
        int rob2 = 0;
        for(auto i = 1; i < nums.size(); ++i)
        {
            int temp = rob1;
            rob1 = max(rob1, nums[i]+rob2);
            rob2 = temp;
        }
        return rob1;
    }
};
