class Solution {
private:
    vector<vector<int>> helper(vector<int> &nums, int i)
    {
        if(nums.size() == i)
            return {{}};

        vector<vector<int>> ret = helper(nums, i+1);
        vector<vector<int>> out;
        for(auto &v : ret)
        {
            for(auto j = 0; j < v.size()+1; ++j)
            {
                vector<int> t = v;
                t.insert(t.begin()+ j, nums[i]);
                out.push_back(t);
            }
        }
        return out;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(nums, 0);
    }
};
