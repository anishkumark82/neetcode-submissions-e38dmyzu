class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Variable length Window based algorithm
        int L = 0;
        int sum = 0;
        int minLen = INT_MAX;
        for(auto R = 0; R < nums.size(); ++R)
        {
            sum += nums[R];
            while(sum >= target && L <= R)
            {
                minLen = min(minLen, R-L+1);
                sum -= nums[L];
                L++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};