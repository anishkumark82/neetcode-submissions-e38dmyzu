class Solution {
public:
    int trap(vector<int>& hts) {
        vector<int> lMax(hts.size(), 0);
        vector<int> rMax(hts.size(), 0);
        for(auto i = 1; i < hts.size(); ++i)
            lMax[i] = max(lMax[i-1], hts[i-1]);

        for(int i = hts.size()-2; i >=0; --i)
            rMax[i] = max(rMax[i+1], hts[i+1]);

        int vol = 0;
        for(int i = 0; i < hts.size(); ++i)
        {
            int minHt = min(lMax[i], rMax[i]);
            vol += (minHt > hts[i]) ? minHt - hts[i] : 0;
        }
        return vol;
    }
};
