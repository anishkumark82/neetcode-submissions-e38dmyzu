struct hashFunc{
    size_t operator()(const pair<int, int> &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class Solution {
private:
    int _dfs(int i, vector<int>&nums, int target, unordered_map<pair<int,int>, int, hashFunc> &memo)
    {
        if(i == nums.size())
            return (target == 0) ? 1 : 0;
        if(memo.find({i, target}) != memo.end())
            return memo[{i, target}];
        memo[{i,target}] = _dfs(i+1, nums, target - nums[i], memo);
        memo[{i,target}] +=  _dfs(i+1, nums, target+nums[i], memo);
        return memo[{i,target}];
    }
public:
    // O(2^n) -- with memoization Time Complexity will become O(n*m) & space Complexity O(m*n)
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int,int>, int, hashFunc> memo; // pair<i, target> where target is curSum
        return (_dfs(0, nums, target, memo));
    }
};
