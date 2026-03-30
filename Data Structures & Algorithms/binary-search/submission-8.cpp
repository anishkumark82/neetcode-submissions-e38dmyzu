class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            int mid = (low + high)/2;
            if(target > nums[mid]) // In the right half array
                low = mid+1;
            else if(nums[mid] > target) // in the left half array
                high = mid-1;
            else
                return mid;
        }
        return -1;
    }
};
