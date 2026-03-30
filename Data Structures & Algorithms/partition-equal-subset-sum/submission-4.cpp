using MAP_PAIR = pair<int,int>;
struct hashFunc{
    size_t operator()(const MAP_PAIR &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class Solution {
    bool _dfs(int i, vector<int>& nums, int target, unordered_map<MAP_PAIR, bool, hashFunc> &memo)
    {
        if(i == nums.size())
            return (target == 0);

        if(memo.find({i, target}) != memo.end())
            return memo[{i, target}];

        // Does not include the number
        memo[{i, target}] = _dfs(i+1, nums, target, memo) 
                            || _dfs(i+1, nums, target - nums[i], memo);

        return memo[{i, target}];
    }
public:
    // Time Complexity O(2^n) -- Space Complexity O(n) 
    // With Memoization Time Complexity O(n*target), Space Complexity- O(n*target)
    bool canPartition(vector<int>& nums) {
        int target = std::accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 != 0) // it is odd so the sum cannot be evenly divided
            return false;
        unordered_map<MAP_PAIR, bool, hashFunc> memo;
        target /= 2;
        return _dfs(0, nums, target, memo);
    }
};
