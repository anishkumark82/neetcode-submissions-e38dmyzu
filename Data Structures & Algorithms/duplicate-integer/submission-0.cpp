class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for(auto &n: nums)
        {
            if(numSet.find(n) != numSet.end())
                return true;
            numSet.insert(n);
        }
        return false;
    }
};
