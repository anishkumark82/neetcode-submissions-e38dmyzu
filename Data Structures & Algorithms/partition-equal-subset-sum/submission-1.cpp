class Solution {
    bool _dfs(int i, vector<int>& nums, int s1, int s2)
    {
        if(i == nums.size())
            return (s1 == s2);
        
        // 1. add the element to the first array
        // 2. add the element in second array. 
        // 3. If either returns true return true
        return (_dfs(i+1, nums,  s1+nums[i], s2)) || (_dfs(i+1, nums, s1, s2+nums[i])); 

    }
public:
    // Time Complexity O(2^n) -- Space Complexity O(n)
    bool canPartition(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        return _dfs(0, nums, s1, s2);
    }
};
