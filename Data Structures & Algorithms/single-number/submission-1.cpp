class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for(auto &n : nums)
            out ^= n;
        
        return out;
    }
};
