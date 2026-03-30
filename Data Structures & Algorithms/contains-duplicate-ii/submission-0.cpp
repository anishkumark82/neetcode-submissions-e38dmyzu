class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> nSet;
        for(int i = 0; i < k && i < nums.size(); ++i)
        {   if(nSet.find(nums[i]) != nSet.end())
                return true;
            nSet.insert(nums[i]);
        }
        
        for(int i = k; i < nums.size(); ++i)
        {
            if(nSet.find(nums[i]) != nSet.end())
                return true;
            nSet.erase(nums[i-k]);
            nSet.insert(nums[i]);
        }
        return false;
    }
};