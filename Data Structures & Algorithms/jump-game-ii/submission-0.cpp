class Solution {
private:
    int _dfs(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == nums.size()-1)
            return 0;
        if(i >= nums.size())
            return -1;

        if(dp[i] != -1)
            return dp[i];

        // I can jump in i+1 .. i+j ways
        if(nums[i] == 0)
            return -1;
        int minJumps = INT_MAX;
        for(auto j = i+1; j <= i+nums[i]; ++j)
        {
            int curJumps = _dfs(j, nums, dp);
            if(curJumps != -1)
                minJumps = min(minJumps, 1 + curJumps);
        }
        dp[i] = minJumps;
        return minJumps;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return _dfs(0, nums, dp);
    }
};
