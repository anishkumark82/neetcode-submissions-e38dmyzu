class Solution {
private:
    vector<vector<int>> _dfs(int i, vector<int> &nums)
    {
        if(i == nums.size())
            return {{}};

        vector<vector<int>> cur = _dfs(i+1, nums);
        vector<vector<int>> out;
        for(auto &j : cur)
            for(auto k = 0; k < j.size()+1; ++k)
            {
                vector<int> temp = j;
                temp.insert(temp.begin() + k, nums[i]);
                out.push_back(temp);
            }
        return out;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return _dfs(0, nums);
    }
};
