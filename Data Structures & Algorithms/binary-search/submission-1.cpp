class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int s, int e)
    {
        if(s <= e)
        {
            int mid = (s + e) / 2;
            if(target > nums[mid]) // on the right half
                return binarySearch(nums, target, mid+1, e);
            else if(target < nums[mid])
                return binarySearch(nums, target, s, mid-1);
            else 
                return mid;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
