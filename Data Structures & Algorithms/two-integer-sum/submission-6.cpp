class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> tMap; // 3 - 0
        // 7 - 4 = is in map.
        for(auto i = 0; i < nums.size(); ++i)
        {
            if(tMap.count(target-nums[i]))
                return {tMap[target-nums[i]], i};
            tMap[nums[i]] = i;
        }
        throw;
    }
};
