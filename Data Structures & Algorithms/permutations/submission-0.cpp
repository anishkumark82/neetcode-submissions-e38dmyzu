class Solution {
private:
    vector<vector<int>> _dfs(vector<int> nums, int i)
    {
        if(i == nums.size())
        {
            return {{}};
        }
        vector<vector<int>> temp = _dfs(nums, i+1);
        vector<vector<int>> out;
        for(auto j = 0; j < temp.size(); ++j)
        {
            for(auto k = 0; k <= temp[j].size(); ++k)
            {
                out.push_back(temp[j]);
                out.back().insert(out.back().begin() + k, nums[i]);
            }
        }
        return out;
    }
public:

    vector<vector<int>> permute(vector<int>& nums) {
        return _dfs(nums, 0);
    }
};
