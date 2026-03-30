class Solution {
public:
    int trap(vector<int>& ht) {
        vector<int> left(ht.size(), 0);

        for(auto i = 1; i < left.size(); ++i)
            left[i] = max(left[i-1], ht[i-1]);

        vector<int> right(ht.size(), 0);
        for(int i = right.size()-2; i >= 0; --i)
            right[i] = max(right[i+1], ht[i+1]);

        int vol = 0;
        for(auto i = 1; i < left.size()-1; ++i)
        {
            int minHt = min(left[i], right[i]);
            vol +=  (minHt > ht[i]) ? minHt-ht[i] : 0;
        }
        return vol;
    }
};
