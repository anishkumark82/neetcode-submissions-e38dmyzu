class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> selected;
        for(auto i = 0; i < triplets.size(); ++i)
            selected.insert(i);

        // Removed all vectors having values greater than target.
        for(auto j = 0; j < target.size(); ++j)
        {
            for(auto itr = selected.begin(); itr != selected.end();)
                if(triplets[*itr][j] > target[j])
                    itr = selected.erase(itr);
                else
                    ++itr;
        }

        vector<bool> match(3, false);
        for(auto &itr : selected)
        {
            if(triplets[itr][0] == target[0]) 
                match[0] = true;

            if(triplets[itr][1] == target[1]) 
                match[1] = true;

            if(triplets[itr][2] == target[2])
                match[2] = true;
        }
        return match[0] && match[1] && match[2];
    }
};
