class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lht(height.size(), 0);

        lht[0] = height[0];
        for(auto i = 1; i < height.size(); ++i)
            lht[i] = max(lht[i-1], height[i]);
        
        int area = 0;
        int rht = height.back();
        for(int i = height.size()-2; i >= 1; --i)
        {
            int pt = 0;
            if(min(lht[i-1], rht) > 0)
                pt = min(lht[i-1], rht) - height[i];
            area +=  (pt > 0) ? pt : 0;
            rht = max(rht, height[i]);
        }

        return area;
        
    }
};
