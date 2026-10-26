class Solution {
public:
    int trap(vector<int>& height) {
        // At each point keep track of the l-max and r-max
        // Then calculate the volume of water at each point
        // sum the volume of water 
        // prefix and postfix sum problem
        vector<int> lMax(height.size(), 0);
        //vector<int> rMax(height.size(), 0);
        int totalVol = 0;

        for(auto i = 1; i < height.size(); ++i)
            lMax[i] = max(lMax[i-1], height[i-1]);
        int rMax = height.back();
        for(int i = height.size()-2; i >= 0; --i)
        {
            rMax = max(rMax, height[i+1]);
            int minHt = min(lMax[i], rMax);
            int vol = (minHt != 0 && minHt > height[i]) ? minHt-height[i] : 0;
            totalVol += vol;
        }
        return totalVol;
    }
};
