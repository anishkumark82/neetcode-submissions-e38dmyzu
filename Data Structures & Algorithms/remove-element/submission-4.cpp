class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 2, 2, 3, 3
        //    |. |
        //
        int k = 0;
        int e = nums.size()-1;
        while(k <= e)
        {
            if(nums[k] == val)
            {
                swap(nums[k], nums[e]);
                e--;
            }
            else
                k++;
        }
        return k;
    }
};