class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nMap;

        for(auto i = 0; i < nums.size(); ++i)
        {
            if(nMap.count(target-nums[i]))
                return {nMap[target-nums[i]], i};
            nMap[nums[i]] = i;
        }
        throw;
    }
};
