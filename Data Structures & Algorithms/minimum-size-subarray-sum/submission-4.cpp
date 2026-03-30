class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0; 
        int r = -1;
        int sum = 0;
        int sN = nums.size();
        int minLen = sN+1;
        
        while(r < sN-1)
        {
            while(sum < target && r < sN-1)
            {
                r++;
                sum += nums[r];
            }

            if(sum >= target)
                minLen = min(minLen, r-l+1);

            while(sum >= target && l <= r)
            {
                sum -= nums[l];
                l++;
                if(sum >= target)
                    minLen = min(minLen, r-l+1);
            }
        }
        return (minLen > sN) ? 0 : minLen;
    }
};