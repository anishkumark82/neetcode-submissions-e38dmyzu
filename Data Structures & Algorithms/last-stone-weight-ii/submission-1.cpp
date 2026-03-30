class Solution {
private:
    int _dfs(int i, vector<int>& stones, int total, 
             int target, int sum, vector<vector<int>> &dp)
    {
        // Termination condition
        if(total >= target || i == stones.size())
            return abs(total - (sum-total));

        if(dp[i][total] != -1)
            return dp[i][total];

        int val = min(_dfs(i+1, stones, total, target, sum, dp),
            _dfs(i+1, stones, total+stones[i], target, sum, dp));
        dp[i][total] = val;
        return val;
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = ceil(sum/2);
        vector<vector<int>> dp(stones.size(), vector<int>(target+1, -1));
        return _dfs(0, stones, 0, target, sum, dp);
    }
};