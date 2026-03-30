class Solution {
public:
    // Brute force - O(2^n) -- Space O(n)
    // Memoization - O(n * sum) 
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
        int n = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(n + 1, false)); 
        for(auto r = 0; r < dp.size(); ++r)
            dp[r][0] = true;

        for(auto c = 0; c < n+1; ++c)
            dp[0][c] = (nums[0] == c) ? true : false;

        for(auto r = 1; r < nums.size(); ++r)
            for(auto c = 1; c < n+1; ++c)
            {
                dp[r][c] = dp[r-1][c];
                if(!dp[r][c] )
                    dp[r][c] = (nums[r] <= c  &&  dp[r-1][c-nums[r]]) ? true : false;
            }
        return dp.back().back();
    }
};
