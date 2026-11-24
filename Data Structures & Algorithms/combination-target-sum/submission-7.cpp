class Solution {
    void _dfs(int i, vector<int> &nums, int target, vector<int> &cur, vector<vector<int>> &out)
    {
        if(target == 0)
        {
            out.push_back(cur);
            return;
        }
        if(target < 0) // Only positive numbers so will not reach the target
            return;

        if(i == nums.size())
            return;
        
        // include the current index
        cur.push_back(nums[i]);
        _dfs(i, nums, target-nums[i], cur, out);
        cur.pop_back();
        // dont include the current index
        _dfs(i+1, nums, target, cur, out);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> out;
        _dfs(0, nums, target, cur, out); 
        return out;
    }
};
