class Solution {
    int _search(vector<int>& nums, int target, int low, int high)
    {
        if(low > high)
            return -1;
        
        int mid = (low + high) / 2;
        if(target < nums[mid])
            return _search(nums, target, low, mid-1);
        if(nums[mid] < target)
            return _search(nums, target, mid+1, high);
        else
            return mid;
    }
public:
    int search(vector<int>& nums, int target) {
        // Recursive Solution        
        return _search(nums, target, 0, nums.size()-1);
    }
};
