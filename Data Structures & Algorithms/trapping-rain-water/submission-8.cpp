class Solution {
public:
    int trap(vector<int>& hts) {
        vector<int> lMax(hts.size(), 0);
        //vector<int> rMax(hts.size(), 0);
        for(auto i = 1; i < hts.size(); ++i)
            lMax[i] = max(lMax[i-1], hts[i-1]);

        int rMax = 0;
        int vol = 0;
        for(int i = hts.size()-1; i >=0; --i)
        {
            int minHt = min(lMax[i], rMax);
            vol += (minHt > hts[i]) ? minHt - hts[i] : 0;
            rMax = max(rMax, hts[i]);
        }
        return vol;
    }
};
