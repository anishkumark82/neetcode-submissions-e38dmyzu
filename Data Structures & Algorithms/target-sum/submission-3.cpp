struct hashFunc{
    size_t operator()(const pair<int,int> &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1 ^ h2;
    }
};
class Solution {
    // DFS -- T-> 2 ^ n, S -> O(n)
    // Memoization or top down 
private:
    int _dfs(int i, vector<int>& nums, int target, 
             unordered_map<pair<int,int>, int, hashFunc> &dp)
    {
        if(i == nums.size())
            return (target == 0) ? 1 : 0;

        if(dp.find({i, target}) != dp.end())
            return dp[{i, target}];

        // either add or subtract
        int total = _dfs(i+1, nums, target - nums[i], dp); // Add number
        total += _dfs(i+1, nums, target + nums[i], dp); // subtract number
        dp[{i, target}] = total; 
        return total;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Dynamic programming problem
        unordered_map<pair<int,int>, int, hashFunc> dp;
        return _dfs(0, nums, target, dp);
    }
};
