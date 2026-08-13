class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        for(auto i = 0; i < nums.size(); ++i)
        {
            int check = target - nums[i];
            if(numMap.count(check))
                return {numMap[check], i};
            numMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};
