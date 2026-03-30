class Solution {
public:
    int maxArea(vector<int>& hts) {
        int l = 0;
        int r = hts.size()-1;
        int maxArea = 0;
        while(l < r)
        {
            maxArea = max(maxArea, (r-l) * min(hts[l], hts[r]));
            if(hts[l] <= hts[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};
