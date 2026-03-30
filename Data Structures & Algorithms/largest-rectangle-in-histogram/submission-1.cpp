class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {
        // Monotonic increasing Stack
        stack<pair<int,int>> s;
        int i = 0;
        int maxArea = 0;
        for(; i < hts.size(); ++i)
        {
            if(s.empty() || s.top().second < hts[i])
                s.push({i, hts[i]});
            else
            {
                int sId = -1;
                while(!s.empty() && s.top().second >= hts[i])
                {
                    sId = s.top().first;
                    int h = s.top().second;
                    s.pop();
                    // calculate area
                    int curArea = (i-sId) * h;
                    maxArea = max(curArea, maxArea);
                }
                s.push({sId, hts[i]});
            }
        }

        while(!s.empty())
        {
            int sId = s.top().first;
            int h = s.top().second;
            s.pop();
            // calculate area
            int curArea = (i-sId) * h;
            maxArea = max(curArea, maxArea);
        }
        return maxArea;
    }
};
