class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curCnt = 0;
        int maxCnt = 0;

        for(auto &n : nums)
        {
            curCnt = (n != 1) ? 0 : curCnt+1;
            maxCnt = max(curCnt, maxCnt);
        }
        return maxCnt;
    }
};