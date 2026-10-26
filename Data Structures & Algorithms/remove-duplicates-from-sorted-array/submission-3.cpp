class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        int p1 = 0;
        int p2 = 1;
        while(p2 < nums.size())
        {
            if(nums[p2] != nums[p1])
            {
                nums[p1+1] = nums[p2];
                p1++;
            }
            p2++;
        }
        return p1+1;
    }
};