class Solution {
private:
    void _dfs(vector<int> &nums, int i, vector<vector<int>> &out, vector<int> &cur)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }

        // Either include element or dont include element
        cur.push_back(nums[i]);
        _dfs(nums, i+1, out, cur);
        cur.pop_back();
        _dfs(nums, i+1, out, cur);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> cur;

        _dfs(nums, 0, out, cur);
        return out;        
    }
};
