class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;

        while(l <= h)
        {
            int mid = (l + h)/2;
            if(nums[mid] == target)
                return mid;
            // Which sorted array is mid part of ???
            if(nums[l] <= nums[mid]) // It is in the left sorted array
            {
                if(target < nums[mid])
                {
                    if(nums[l] <= target) // Target is in the left sorted array
                        h = mid-1;
                    else
                        l = mid+1;
                }
                else //if(target > nums[mid])
                    l = mid+1;
            }
            else // if(nums[mid] <= nums[h]) -- Target on the right sorted array
            {
                if(nums[mid] < target)
                {
                    if(target <= nums[h]) // It is in the same right sorted array
                        l = mid+1;
                    else
                        h = mid-1;
                }
                else // target < nums[mid]
                    h = mid-1;
            }
        }
        return -1;
    }
};
