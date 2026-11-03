class Solution {
public:
    int bSearch(vector<int>&nums, int target, int low, int high)
    {
        if(low > high)
            return -1;
        int mid = (low + high) / 2;
        if(nums[mid] < target)
            return bSearch(nums, target, mid+1, high);
        if(target < nums[mid])
            return bSearch(nums, target, low, mid-1);
        return mid;
    }
    int search(vector<int>& nums, int target) {
        return bSearch(nums, target, 0, nums.size()-1);
    }
};
