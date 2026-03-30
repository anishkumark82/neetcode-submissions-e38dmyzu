class Solution {
private:
    vector<vector<int>> _dfs(vector<int> nums, int i)
    {
        if(i == nums.size())
            return {{}};

        vector<vector<int>>temp = _dfs(nums, i+1);
        vector<vector<int>> out;
        for(auto &t : temp)
        {
            for(auto j = 0; j <= t.size(); ++j)
            {
                out.push_back(t);
                out.back().insert(out.back().begin()+j, nums[i]);
            }
        }
        return out;
    }
public:

    vector<vector<int>> permute(vector<int>& nums) {
        return _dfs(nums, 0);
    }
};
