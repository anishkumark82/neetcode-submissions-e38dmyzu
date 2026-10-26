class Solution {
    // 1, 1, 2, 2, 2, 3, 3, 3
    //       p1
    //             p2
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 0;
        int R = 0;
        int dupCnt = 0;
        while(R < nums.size())
        {
            int curNum = nums[R];
            while(dupCnt == 0 || (R < nums.size() && nums[R] == nums[R-1]))
            {
                dupCnt++;
                R++;
            }

            nums[L++] = curNum;
            if(dupCnt > 1)
                nums[L++] = curNum;
            dupCnt = 0;
        }
        return L;
    }
};