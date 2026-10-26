class Solution {
public:
    int maxArea(vector<int>& ht) {
        int mArea = 0;
        int L = 0;
        int R = ht.size()-1;

        while(L < R)
        {
            int area = min(ht[L], ht[R]) * (R - L);
            mArea = max(area, mArea);
            if(ht[L] < ht[R])
                L++;
            else
                R--;
        }
        return mArea;
    }
};
