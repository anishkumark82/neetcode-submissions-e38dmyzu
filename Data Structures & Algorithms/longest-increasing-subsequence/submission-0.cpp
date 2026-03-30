class Solution {
    int _dfs(int i, int prev, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(i == nums.size())
            return 0;
        
        if(dp[i][1001+prev] != -1)
            return dp[i][1001+prev];
        // skip 
        int maxSeq = _dfs(i+1, prev, nums, dp);
        
        // include
        if(nums[i] > prev)
            maxSeq = max(maxSeq, 1 + _dfs(i+1, nums[i], nums, dp));
        dp[i][1001+prev] = maxSeq;
        return maxSeq;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int total = 2002;
        vector<vector<int>>dp(nums.size(), vector<int>(total, -1));
        return _dfs(0, -1001, nums,dp);
    }
};
