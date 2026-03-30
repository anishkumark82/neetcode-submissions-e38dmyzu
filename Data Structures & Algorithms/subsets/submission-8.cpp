class Solution {
private:
    void _dfs(int i, vector<int> &nums, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }
        
        // skip 
        _dfs(i+1, nums, cur, out);

        // include
        cur.push_back(nums[i]);
        _dfs(i+1, nums, cur, out);
        cur.pop_back();

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> cur;
        _dfs(0, nums, cur, out);
        return out;
    }
};
