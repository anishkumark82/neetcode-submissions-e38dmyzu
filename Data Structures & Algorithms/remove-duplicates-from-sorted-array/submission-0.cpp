class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1, 2, 4, 6, 4, 6
        //          i
        //.               j 
        if(nums.size() <= 1)
            return nums.size();
        
        int i = 0;
        for(auto j = 1; j < nums.size(); ++j)
        {
            if(nums[i] == nums[j])
                continue;
            i++;
            nums[i] = nums[j];
        }
        return i+1;
    }
};