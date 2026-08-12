class Solution {
public:
    void _dfs(vector<int>&nums, int i, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }
        
        // Without the current element
        _dfs(nums, i+1, cur, out);
        cur.push_back(nums[i]);
        _dfs(nums, i+1, cur, out);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> cur;
        _dfs(nums, 0, cur, out);
        return out;    
    }
};
