class Solution {
private:
    int _dfs(int i, vector<int>&nums, int target)
    {
        if(i == nums.size())
            return (target == 0) ? 1 : 0;
        int count = _dfs(i+1, nums, target - nums[i]);
        count +=  _dfs(i+1, nums, target+nums[i]);
        return count;
    }
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        return (_dfs(0, nums, target));
    }
};
