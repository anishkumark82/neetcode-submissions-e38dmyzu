class Solution {
public:
    int rob(vector<int>& nums) {
        // 2 9 8 3 6
        // 2 9 10 12 16

        if(nums.size() <= 2)
            return *max_element(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(auto i = 2; i < nums.size(); ++i)
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        
        return dp.back();
    }
};
