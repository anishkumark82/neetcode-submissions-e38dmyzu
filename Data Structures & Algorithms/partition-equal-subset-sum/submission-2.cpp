using MEM_TUPLE = tuple<int,int,int>;
struct hashFunc{
    size_t operator()(const MEM_TUPLE &p) const {
        auto h1 = hash<int>{}(get<0>(p));
        auto h2 = hash<int>{}(get<1>(p));
        auto h3 = hash<int>{}(get<2>(p));
        return h1 ^ (h2 ^ h3);
    }
};
class Solution {
    bool _dfs(int i, vector<int>& nums, int s1, int s2, unordered_map<MEM_TUPLE, bool, hashFunc> &memo)
    {
        if(i == nums.size())
            return (s1 == s2);
        
        if(memo.find(make_tuple(i, s1, s2)) != memo.end())
            return memo[make_tuple(i, s1, s2)];

        // 1. add the element to the first array
        // 2. add the element in second array. 
        // 3. If either returns true return true
        memo[make_tuple(i, s1, s2)] = (_dfs(i+1, nums,  s1+nums[i], s2, memo)) 
                                      || (_dfs(i+1, nums, s1, s2+nums[i], memo)); 
        return memo[make_tuple(i, s1, s2)];
    }
public:
    // Time Complexity O(2^n) -- Space Complexity O(n) -- With Memoization it can come down to O(n^2)
    bool canPartition(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        unordered_map<MEM_TUPLE, bool, hashFunc> memo; // Key is i, s1, s2 for a given index
        return _dfs(0, nums, s1, s2, memo);
    }
};
