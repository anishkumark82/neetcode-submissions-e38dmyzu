class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> selected;
        for(auto &t : triplets)
        {
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue; // skip the triplet
            
            for(auto i = 0; i < 3; ++i)
                if(target[i] == t[i])
                    selected.insert(i);
        }
        return selected.size() == 3;
    }
};
