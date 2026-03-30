class Solution {
    bool _dfs(int i, vector<int>& nums, int target)
    {
        if(i == nums.size())
            return (target == 0);

        // Does not include the number
        return _dfs(i+1, nums, target) || _dfs(i+1, nums, target - nums[i]);
    }
public:
    // Time Complexity O(2^n) -- Space Complexity O(n) -- With Memoization it can come down to O(n)
    bool canPartition(vector<int>& nums) {
        int target = std::accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 != 0) // it is odd so the sum cannot be evenly divided
            return false;
        target /= 2;
        return _dfs(0, nums, target);
    }
};
