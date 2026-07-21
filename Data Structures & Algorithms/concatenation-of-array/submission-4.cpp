class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> out = nums;
        out.insert(out.end(), nums.begin(), nums.end());
        return out;
    }
};