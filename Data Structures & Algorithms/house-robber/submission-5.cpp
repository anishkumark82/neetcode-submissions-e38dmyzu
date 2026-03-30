class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() <= 2)
        {
            int maxVal = *max_element(nums.begin(), nums.end());    
            return maxVal;
        }

        int p2 = nums[0];
        int p1 = max(nums[0], nums[1]);
        for(auto i = 2; i < nums.size(); ++i)
        {
            int temp = p1;
            p1 = max(p1, nums[i]+p2);
            p2 = temp;    
        }
        return p1;
    }
};
