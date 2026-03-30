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

        for(auto j = i;j < nums.size(); ++j)
        {
            cur.push_back(nums[j]);
            target -= nums[j];
            dfs(nums, j, cur, out,target);
            cur.pop_back();
            target += nums[j];
        }    
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>>out;
        dfs(nums, 0, cur, out,target);
        return out;
    }
};
