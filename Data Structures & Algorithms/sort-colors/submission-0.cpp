class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0, 1, 2

        // Bucket Sort
        vector<int>count(3, 0);
        for(auto &n : nums)
            count[n]++;
        
        int i = 0;
        for(auto j = 0; j < 3; ++j)
            for(auto k = 0; k < count[j]; ++k)
                nums[i++] = j;
    }
};