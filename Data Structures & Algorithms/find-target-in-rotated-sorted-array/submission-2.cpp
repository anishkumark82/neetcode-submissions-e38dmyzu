class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;

        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(nums[mid] == target)
                return mid;

            // Determine if mid is in the left sorted array or in the right sorted array
            if(nums[l] <= nums[mid]) // In left sorted array
            {
                if(target < nums[mid])
                {
                    if(nums[l] <= target)
                        h = mid-1;
                    else
                        l = mid+1;
                }
                else // target > nums[mid] // This is in left sorted Array so it has to be in the right
                    l = mid+1;
            }
            else if(nums[mid] <= nums[h]) // in right sorted array
            {
                if(nums[mid] < target)
                {
                    if(target <= nums[h])
                        l = mid+1;
                    else // it is in the left sorted array
                        h = mid-1;
                }
                else
                    h = mid-1;
            }
        }
        return -1;
    }
};
