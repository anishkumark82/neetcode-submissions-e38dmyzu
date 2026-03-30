class Solution {
private:
    bool _dfs(int i, vector<int>& nums, int total)
    {
        
        if(total == 0)
            return true;

        if(total < 0)
            return false;

        if(i == nums.size())
            return false;
        
        // Skip
        bool valid = _dfs(i+1, nums, total);

        // include
        if(!valid)
            valid = _dfs(i+1, nums, total - nums[i]);

        return valid;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 0x01 == 0x01) // It is odd and cannot be divided into equal sum
            return false;
        
        int total = sum/2;
        return _dfs(0, nums, total);
    }
};
