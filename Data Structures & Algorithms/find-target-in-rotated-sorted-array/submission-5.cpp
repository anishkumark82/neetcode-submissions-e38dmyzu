class Solution {
    // [3,  4,  5,  6,  1,  2]
    //              L        
    //                      H
    //                  M

    // target = 1;
    // [5,  6,  1,  2,  3,  4]
    //  L        
    //                      H
    //          M

public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;

        while(l <= h)
        {
            int mid = (l + h) / 2;

            if(nums[mid] == target)
                return mid;

            // Check in left sorted array
            if(nums[l] <= nums[mid])
            {
                if(target > nums[mid])
                    l = mid+1;
                else if(target < nums[l])
                    l = mid + 1;
                else
                    h = mid-1; // In the current sorted array
            }
            else // right sorted array
            {
                if(target < nums[mid])
                    h = mid-1;
                else if(target > nums[h])
                    h = mid-1;
                else
                    l = mid + 1; // in the right sorted array
            }

        }
        return -1;
    }
};
