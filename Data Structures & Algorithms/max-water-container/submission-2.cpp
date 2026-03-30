class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size()-1;
        int maxVal = 0;
        while(l <= r)
        {
            int area = min(heights[r], heights[l]) * (r-l);
            maxVal = max(area, maxVal);
            if(heights[l] <= heights[r])
                l++;
            else
                r--;
        }
        return maxVal;

    }
};
