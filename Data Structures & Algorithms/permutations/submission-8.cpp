class Solution {
    // 1, 2, 3
private:
    vector<vector<int>> _dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
            return {{}}; 
        
        vector<vector<int>> tmpOut = _dfs(nums, i+1); // {{3,4}, {4,3}}
        vector<vector<int>> out{};//{}
        
        for(auto &o : tmpOut) 
        {
            // 3. o {4,3}
            for(auto j = 0; j < o.size()+1; ++j)
            {
                vector<int> tmp = o; //{4,3}
                tmp.insert(tmp.begin()+j, nums[i]); //{4,3,2}
                out.push_back(tmp); // {{2,3,4}, {3,2,4}, {3,4,2}, {2,4,3}, {4,2,3},{4,3,2}}
            }
        }
        return out;

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return _dfs(nums, 0);
    }
};
