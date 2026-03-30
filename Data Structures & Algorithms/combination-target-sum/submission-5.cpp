class Solution {
private:
    void _dfs(int i, vector<int> &nums, vector<int>&cur, vector<vector<int>>&out, int target)
    {
        if(target == 0)
        {
            out.push_back(cur);
            return;
        }    

        if(i == nums.size())
            return;
        
        // skip
        _dfs(i+1, nums, cur, out, target);

        if(target-nums[i] >= 0)
        {
            cur.push_back(nums[i]);
            _dfs(i, nums, cur, out, target-nums[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> out;
        _dfs(0, nums, cur, out, target);
        return out;
    }
};
