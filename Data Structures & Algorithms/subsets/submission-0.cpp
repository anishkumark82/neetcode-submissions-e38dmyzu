class Solution {
public:
    void findSubSets(vector<int>& nums, int i, vector<vector<int>> &out)
    {
        if(i == nums.size())
        {
            out.push_back({});
            return;
        }
        findSubSets(nums, i+1, out);
        int cSize = out.size();
        for(auto j = 0; j < cSize; ++j)
        {
            out.push_back(out[j]);
            out.back().push_back(nums[i]);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        findSubSets(nums, 0, out);
        return out;
    }
};
