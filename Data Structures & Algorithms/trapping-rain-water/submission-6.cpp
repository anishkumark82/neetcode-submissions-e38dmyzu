class Solution {
public:
    int trap(vector<int>& ht) {
        vector<int> left(ht.size(), 0);

        for(auto i = 1; i < left.size(); ++i)
            left[i] = max(left[i-1], ht[i-1]);

        int rMax = 0;
        int vol = 0;
        for(int i = ht.size()-2; i >= 0; --i)
        {
            rMax = max(rMax, ht[i+1]);
            int minHt = min(left[i], rMax);
            vol +=  (minHt > ht[i]) ? minHt-ht[i] : 0;
            
        }

        return vol;
    }
};
