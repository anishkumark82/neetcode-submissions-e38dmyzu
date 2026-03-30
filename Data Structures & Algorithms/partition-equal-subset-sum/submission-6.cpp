class Solution {
public:
    // Brute force - O(2^n) -- Space O(n)
    // 
    bool _dfs(int i, vector<int> &nums, int cur, int sum, vector<vector<int>> &dp)
    {
        if(cur == sum)
            return true;
        
        if(i == nums.size())
            return false;
        
        if(dp[i][cur] != -1)
            return (dp[i][cur]);
        // Dont include the current element
        bool status = _dfs(i+1, nums, cur, sum, dp);
        if(!status && cur+nums[i] <= sum)
            status = _dfs(i+1, nums, cur+nums[i], sum, dp);
        dp[i][cur] = status ? 1 : 0;
        return status;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2, -1)); 
        return _dfs(0, nums, 0, sum/2, dp);
    }
};
