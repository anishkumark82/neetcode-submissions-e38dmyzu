class Solution {
public:
    int quickSelect(vector<int> &nums, int l, int h) // nums = [2,3,1,5,4], l = 0, h = 4
    {
        // nums = [2,3,1,4,5],
        //               le
        //               i 
        int pivot = nums[h]; // 4
        int left = l; // 0
        for(auto i = l; i < h; ++i)
        {
            if(nums[i] < pivot)
            {
                swap(nums[i], nums[left]);
                left++;
            }
        }
        swap(nums[left], nums[h]);
        return left;
    }
    int findKthLargest(vector<int>& nums, int k) {
        // Do a quickselect algorithm

        int p = -1;
        int l = 0;
        int n = nums.size();
        int h = n-1;
        // nums = [2,3,1,5,4], k = 2
        //         l       h
        // l = 0; h = 4; n = 5; k = 2
        // p = -1
        // pivot = 4 ( 
        int target = n-k;
        while(p != target)
        {
            p = quickSelect(nums, l, h); // 4
            if(p > target)
                h = p-1;
            else if(p < target)
                l = p+1;
            else 
                return nums[target];
        }
        throw;
    }
};
