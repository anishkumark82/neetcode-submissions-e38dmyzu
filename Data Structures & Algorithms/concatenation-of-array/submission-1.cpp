class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret = nums;
        for(auto i = 0; i < nums.size(); ++i)
            ret.push_back(nums[i]);
        return ret;
    }
};