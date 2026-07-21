class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curCnt = 0;
        int maxCnt = 0;

        for(auto &n : nums)
        {
            if (n != 1)
            {
                maxCnt = max(maxCnt, curCnt);
                curCnt = 0;
            }
            else
                curCnt++;
        }
        maxCnt = max(maxCnt, curCnt);
        return maxCnt;
    }
    
};