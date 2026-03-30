class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numsMap;

        for(auto i = 0; i < nums.size(); ++i)
        {
            if(numsMap.find(target - nums[i]) != numsMap.end())
                return {numsMap[target - nums[i]], i };
            numsMap[nums[i]] = i;
        }
        return {-1,-1};
    }
};
