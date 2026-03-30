class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret(2*nums.size(), 0);
        auto n = nums.size();
        for(auto i = 0; i < nums.size(); ++i)
        {
            ret[i] = nums[i];
            ret[i+n] = nums[i];
        }
        return ret;
    }
};