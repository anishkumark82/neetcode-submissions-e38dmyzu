class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int h = nums.size()-1;
        int minE = nums[0];
        while(l <= h)
        {
            if(nums[l] <= nums[h]) // sorted sub-array
                return min(nums[l], minE);
            
            int mid = (l + h) / 2;
            if(nums[l] <= nums[mid]) // left sorted array
            {
                minE = min(nums[l], minE);
                l = mid+1;
            }
            else // right sorted array - all values to right > current number
            {
                minE = min(nums[mid], minE);
                h = mid - 1;
            }
        }
        return minE;
    }
};
