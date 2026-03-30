class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>> &out, vector<int>&subset, int idx)
    {
        if(idx == nums.size())
        {
            out.push_back(subset);
            return;
        }

        // Path with adding current element
        subset.push_back(nums[idx]);
        dfs(nums, out, subset, idx+1);
        subset.pop_back();
        dfs(nums, out, subset, idx+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> subset;
        dfs(nums, out, subset, 0);
        return out; 
    }
};
