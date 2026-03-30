class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int s, int e)
    {
        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(target > nums[mid]) // on the right half
                s = mid+1;
            else if(target < nums[mid])
                e = mid-1;
            else 
                return mid;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
