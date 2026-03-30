class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        vector<int>dp(2, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(auto i = 2; i < nums.size(); ++i)
        {
            int tmp = dp[1];
            dp[1] = max(dp[0]+nums[i], dp[1]);
            dp[0] = tmp;
        }
        return dp[1];
    }
};
