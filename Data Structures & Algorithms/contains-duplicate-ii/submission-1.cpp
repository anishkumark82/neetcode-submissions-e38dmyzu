class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // Return true if there is a duplicate in window size of k
        // [1, 2 ,3, 1]
        //. L        R 
        unordered_set<int> nSet;
        for(auto i = 0; i <= k && i < nums.size(); ++i)
        {
            if(nSet.count(nums[i]))
                return true;
            nSet.insert(nums[i]);
        }
        int L = 0;
        int R = k+1;
        while(R < nums.size())
        {
            nSet.erase(nums[L]);
            L++;
            if(nSet.count(nums[R]))
                return true;
            nSet.insert(nums[R]);
            R++;
        }
        return false;
    }
};