class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nSet(nums.begin(), nums.end());
        return (nSet.size() != nums.size());
    }

    
};