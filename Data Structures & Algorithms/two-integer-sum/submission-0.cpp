class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numSet;
        for(auto i = 0; i < nums.size(); ++i)
        {
            if(numSet.find(target-nums[i]) != numSet.end())
                return {numSet[target-nums[i]], i};
            numSet[nums[i]] = i;
        }
        return {-1,-1};
    }
};
