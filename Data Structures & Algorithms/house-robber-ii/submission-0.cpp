class Solution {
private:
    int rob1(vector<int>& nums, int i, int j)
    {
        int n = nums.size();
        int prev2 = nums[i];
        int prev1 = max(nums[i+1], nums[i]);
        for(auto k = i+2; k <= j; ++k)
        {
            int temp = prev1;
            prev1 = max(prev1, prev2+ nums[k]);
            prev2 = temp;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 0)
            return 0;

        int max1 = rob1(nums, 0, nums.size()-2);
        int max2 = rob1(nums, 1, nums.size()-1);
        return max(max1, max2);


    }
};
