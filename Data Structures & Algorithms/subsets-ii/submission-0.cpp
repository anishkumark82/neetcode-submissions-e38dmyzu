class Solution {
private:
    void _dfs(vector<int> &nums, int i, vector<int> & cur, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back(cur);
            return;
        }

        // the path where the current number is included remains same.
        cur.push_back(nums[i]); 
        _dfs(nums, i+1, cur, out);
        cur.pop_back();

        
        // continue to not include the duplicates to the right
        int j = i;
        while(i+1 != nums.size() && nums[i+1] == nums[j])
            i++;
        _dfs(nums, i+1, cur, out);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<vector<int>> out;

        _dfs(nums, 0, cur, out);
        return out;
    }
};
