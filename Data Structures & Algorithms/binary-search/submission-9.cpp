class Solution {
private:
    int bSearch(vector<int>& nums, int low, int high, int target)
    {
        if(low > high)
            return -1;
        
        int mid = (low + high) / 2;
        if(target > nums[mid])
            return bSearch(nums, mid+1, high, target);
        else if(nums[mid] > target)
            return bSearch(nums, low, mid-1, target);
        return mid;
    }
public:
    int search(vector<int>& nums, int target) {
        return bSearch(nums, 0, nums.size()-1, target);
    }
};
