class Solution {
public:
    int trap(vector<int>& ht) {
        vector<int> lTall(ht.size(), 0); 
        for(auto i = 1; i < ht.size(); ++i)
            lTall[i] = max(lTall[i-1], ht[i-1]); 
        
        vector<int> rTall(ht.size(), 0);
        for(int i = ht.size()-2; i >=0; --i)
            rTall[i] = max(rTall[i+1], ht[i+1]); 

        int vol = 0;
        for(auto i = 1; i < ht.size()-1; ++i)
        {
            if(ht[i] < lTall[i] && ht[i] < rTall[i])
                vol += min(lTall[i], rTall[i]) - ht[i];
        }
        return vol;
    }
};
