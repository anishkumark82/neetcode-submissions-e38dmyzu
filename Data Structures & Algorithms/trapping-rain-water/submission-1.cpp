class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lht(height.size(), 0);
        vector<int> rht(height.size(), 0);

        lht[0] = height[0];
        for(auto i = 1; i < height.size(); ++i)
            lht[i] = max(lht[i-1], height[i]);
        
        int area = 0;
        rht.back() = height.back();
        for(int i = height.size()-2; i >= 1; --i)
        {
            int pt = 0;
            if(min(lht[i-1], rht[i+1]) > 0)
                pt = min(lht[i-1], rht[i+1]) - height[i];
            area +=  (pt > 0) ? pt : 0;
            rht[i] = max(rht[i+1], height[i]);
        }

        return area;
        
    }
};
