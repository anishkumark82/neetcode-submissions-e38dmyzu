class hashFunc{
public:
    std::size_t operator()(const pair<int,int> &p) const
    {
        auto a = hash<int>{}(p.first);
        auto b = hash<int>{}(p.second);
        return a^b;
    }
};
class Solution {
private:
    int _dfs(int i, vector<int>& nums, int cur, int target, unordered_map<pair<int,int>, int, hashFunc> &dp)
    {
        if(i == nums.size())
            return (cur == target) ? 1 : 0;
        
        if(dp.find({i, cur}) != dp.end())
            return dp[{i, cur}];
        // 2 paths (1) add and (2) subtract
        int cnt = _dfs(i+1, nums, cur+nums[i], target, dp);
        cnt += _dfs(i+1, nums, cur-nums[i], target, dp);
        dp[{i,cur}] = cnt;

        return cnt;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int,int>, int, hashFunc> dp;
        return _dfs(0, nums, 0, target, dp);
    }
};
