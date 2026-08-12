class Solution {
public:
    void _dfs(vector<int> &nums, int i, vector<int> &cur, vector<vector<int>> &out, int target)
    {
        if(nums.size() == i)
        {
            if(target == 0)
                out.push_back(cur);
            return;
        }

        // Where the current is not included
        _dfs(nums, i+1, cur, out, target);
        if(target - nums[i] >= 0)
        {
            cur.push_back(nums[i]);
            _dfs(nums, i, cur, out, target-nums[i]);    
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>>out;
        _dfs(nums, 0, cur, out, target);
        return out;
    }
};
