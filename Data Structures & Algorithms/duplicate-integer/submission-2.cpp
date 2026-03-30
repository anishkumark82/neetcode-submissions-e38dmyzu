class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nSet;
        for (auto &n : nums)
        {
            if (nSet.find(n) != nSet.end())
                return true;
            nSet.insert(n);
        }
        return false;
    }
};