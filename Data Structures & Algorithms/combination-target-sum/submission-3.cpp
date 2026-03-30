class Solution {
private:
    void dfs(vector<int>&nums, vector<vector<int>> &out, vector<int>&cur, int target, int idx)
    {
        if(target == 0)
        {
            out.push_back(cur);
            return;
        }
        
        if(target < 0 || idx == nums.size())
            return;

        cur.push_back(nums[idx]);
        // Include current idx.
        dfs(nums, out, cur, target-nums[idx], idx);
        cur.pop_back();
        dfs(nums, out, cur, target, idx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> out; 
        dfs(nums, out, cur, target, 0);
        return out;
    }
};
