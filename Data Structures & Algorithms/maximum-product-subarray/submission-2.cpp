class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //          [-4,    1,  -3, 1,  -2, 10]
        //  min      -4    -4.  -3  -3. -24   
        //  max      -4     1.  12. 12.  6 
        // maxProd   
        //-6, -3, -24

        // nums=[-2,    3,  -4]
        // min   -2     -6  -12
        // max.  -2     3   24 

        int curMin = 1;
        int curMax = 1;
        int maxProd = nums[0];

        // -2 -1
        //     |
        // curMin = 2 1
        // curMax = 2 2
        // maxProd = -2
        for(auto i = 0; i < nums.size(); ++i)
        {
            curMin *= nums[i];
            curMax *= nums[i];

            int tmp = curMin;
            // find what is the minimum at this point
            curMin = min(min(curMin,curMax), nums[i]);
            curMax = max(max(curMax, tmp), nums[i]);
            maxProd = max(curMax, maxProd);
        }
        return maxProd;
        
    }
};
