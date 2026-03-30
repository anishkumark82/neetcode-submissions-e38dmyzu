class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int minLen = nums.size()+1;
        int sum = 0;
        for(auto r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            if(sum >= target)
            {
                minLen = min(minLen, r-l+1);
                while(l <= r)
                {
                    sum -= nums[l];
                    l++;
                    if(sum >= target)
                        minLen = min(minLen, r-l+1); 
                    else
                        break;
                }
            }
        }
        return minLen > nums.size() ? 0 : minLen;
    }
};