class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 2, 2, 3, 3
        //   ik 
        int i = 0;
        int k = nums.size()-1;
        while(i <= k)
        {
            if(nums[i] == val)
            {
                swap(nums[i], nums[k]);
                k--;
            }
            else
                i++;
        }
        return k+1;
    }
};