class Solution {
public:
    int maxArea(vector<int>& hts) {
        int maxVal = 0;

        int L = 0;
        int R = hts.size()-1;
        while(L < R)
        {
            int curArea = min(hts[L], hts[R]) * (R-L);
            maxVal = max(maxVal, curArea);
            if(hts[L] < hts[R])
                L++;
            else
                R--;
        }
        return maxVal;
    }
};
