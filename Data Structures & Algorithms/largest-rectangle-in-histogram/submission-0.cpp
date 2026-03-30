class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {
        // O(n^2)
        int maxArea = 0;
        for(auto i = 0; i < hts.size(); ++i)
        {
            int localMin = hts[i];
            for(auto j = i; j < hts.size(); ++j)
            {
                localMin = min(localMin, hts[j]);
                int curArea = localMin * (j-i + 1);
                maxArea = max(maxArea, curArea);
            }
        }
        return maxArea;
    }
};
