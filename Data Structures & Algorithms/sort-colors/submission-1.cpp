class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Bucket sort
        vector<int>cCnt(3, 0);
        for(auto &n : nums)
            cCnt[n]++;
        
        for(auto i = 0; i < nums.size(); ++i)
            for(auto j = 0; j < 3; ++j)
            {
                while(cCnt[j] != 0)
                {
                    cCnt[j]--;
                    nums[i++] = j;
                }
            }
    }
};