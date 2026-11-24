class Solution {
private:
    void _dfs(vector<int> &nums, int i, vector<int> &cur, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }

        // path that includes the current element
        cur.push_back(nums[i]);
        _dfs(nums, i+1, cur, out);
        cur.pop_back();

        // path that does not include duplicate of the current elements
        while(i+1 < nums.size() && nums[i+1] == nums[i])
            i++;
        _dfs(nums, i+1, cur, out);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        _dfs(nums, 0, cur, out);
        return out;
    }
};
