class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq(20001, 0);
        for(auto &n : nums)
            freq[n+10000]++; 

        for(auto i = 0; i < 20001; ++i)
            if(freq[i] == 1)
                return i-10000;
        throw;
    }
};
