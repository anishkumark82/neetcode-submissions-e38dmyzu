class Solution {
public:
    void dfs(vector<int> &nums, int i, vector<int> &cur, vector<vector<int>>& out, int target)
    {
        if(target == 0)
        {
            out.push_back(cur);
            return;
        }
        if((target < 0) || i == nums.size())
            return;

        cur.push_back(nums[i]);
        dfs(nums, i, cur, out, target-nums[i]); // include the number 
        cur.pop_back();
        dfs(nums, i+1, cur, out, target); // dont include the number
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>>out;
        dfs(nums, 0, cur, out,target);
        return out;
    }
};
