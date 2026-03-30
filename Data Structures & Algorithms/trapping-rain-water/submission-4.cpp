class Solution {
public:
    int trap(vector<int>& ht) {
        vector<int> lTall(ht.size(), 0); 
        for(auto i = 1; i < ht.size(); ++i)
            lTall[i] = max(lTall[i-1], ht[i-1]); 
        
        int rMax = 0;
        int vol = 0;
        for(int i = ht.size()-2; i >=0; --i)
        {
            rMax = max(rMax, ht[i+1]); 
            if(ht[i] < lTall[i] && ht[i] < rMax)
                vol += min(lTall[i], rMax) - ht[i];
        }

        return vol;
    }
};
