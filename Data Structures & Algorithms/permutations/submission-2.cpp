class Solution {
private:
    vector<vector<int>> _dfs(int i, vector<int> &nums)
    {
        if(i == nums.size())
            return {{}};
        
        vector<vector<int>> ret = _dfs(i+1, nums);
        // Insert nums[i] in each position of each element in the array.
        vector<vector<int>> out;
        for(auto &tmp : ret)
        {
            for(auto j = 0; j <= tmp.size(); ++j)
            {
                out.push_back(tmp);
                out.back().insert(out.back().begin()+j, nums[i]);
            }
        }
        return out;
    }    

public:
    vector<vector<int>> permute(vector<int>& nums) {
        return _dfs(0, nums);
    }
};
