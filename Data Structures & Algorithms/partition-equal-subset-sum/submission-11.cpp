class Solution {
private:
    bool _dfs(int i, vector<int>& nums, int total, vector<vector<int>> &dp)
    {
        if(total == 0)
            return true;

        if(total < 0)
            return false;

        if(i == nums.size())
            return false;

        if(dp[i][total] != -1)
            return (dp[i][total]);        
        // Skip
        bool valid = _dfs(i+1, nums, total, dp);

        // include
        if(!valid)
            valid = _dfs(i+1, nums, total - nums[i], dp);
        dp[i][total] = (valid) ? 1 : 0; 
        return valid;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 0x01 == 0x01) // It is odd and cannot be divided into equal sum
            return false;
        
        int total = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(total+1, false));
        for(auto r = 0; r < dp.size(); ++r)
            dp[r][0] = true;
        
        for(auto c = 0; c <= total; ++c)
            dp[0][c] = (nums[0] == c);
        
        for(auto r = 1; r < nums.size(); ++r)
            for(auto c = 1; c <= total; ++c)
            {
                // skip
                dp[r][c] = dp[r-1][c];
                // include
                if(!dp[r][c] && nums[r] <= c)
                    dp[r][c] = dp[r-1][c-nums[r]];
            }
        
        return dp.back().back();
    }
};
