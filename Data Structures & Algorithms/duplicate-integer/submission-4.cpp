class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nSet;
        for(auto &n : nums)
        {
            if(nSet.count(n))
                return true;
            nSet.insert(n);
        }
        return false;
    }
};