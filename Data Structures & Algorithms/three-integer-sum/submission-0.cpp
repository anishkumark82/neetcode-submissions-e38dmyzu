class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // [-1,  0,  1,  2,  -1, -4]
        // [-4, -1, -1,  0,   1   2] -- sorted
        //               i
        //.                   j   
        //                        k
        // target = 1
        // sum = 0 + 1 = 1
        // out {{-1, -1, 2}, {-1, 0, 1}}
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        
        for(auto i = 0; i < nums.size()-2; ++i)
        {
            while(i > 0 && i < nums.size()-2 && nums[i] == nums[i-1])
                i++;
            
            if(i >= nums.size()-2)
                continue;
            
            int target = -1 * nums[i];
            int j = i+1;
            int k = nums.size()-1;

            while(j < k)
            {
                int sum = nums[j] + nums[k];
                if(sum == target)
                {
                    out.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                }
                else if(sum > target)
                    k--;
                else
                    j++;
            }
        }
        return out;
    }
};

