class Solution {
public:
    // Brute force - Time - O(2^n) -- Space O(n)
    // Memoization - Time - O(n * sum), Space O(n * sum) 
    // Bottom Up without space optimization - Time - O(n * sum), Space O(n * sum) 
    // Bottom Up with space optimization - Time - O(n * sum), Space O(sum) 
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
        //vector<vector<bool>> dp(nums.size(), vector<bool>(n + 1, false)); 
        vector<bool>dp(n + 1, false); 
        vector<bool>newDp(n + 1, false); 
        dp[0] = true;

        for(auto c = 0; c < n+1; ++c)
            dp[c] = (nums[0] == c) ? true : false;

        for(auto r = 1; r < nums.size(); ++r)
        {
            for(auto c = 1; c < n+1; ++c)
            {
                newDp[c] = dp[c];
                if(!newDp[c] )
                    newDp[c] = (nums[r] <= c  &&  dp[c-nums[r]]) ? true : false;
            }
            dp = newDp;
        }
        return dp.back();
    }
};
