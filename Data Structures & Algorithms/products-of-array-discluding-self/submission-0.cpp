class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lProd(nums.size(), 1);
        for(auto i = 0; i < nums.size(); ++i)
            if(i == 0)
                lProd[i] = nums[i];
            else
                lProd[i] = nums[i] * lProd[i-1];
            //lProd[i] = ((i == 0) ? 1 : lProd[i-1]) * nums[i]; 

        vector<int> out(nums.size(), 1);
        int rProd = 1;
        for(int i = nums.size()-1; i >=0; --i)
        {
            if( i == 0)
                out[i] = rProd;
            else
                out[i] = lProd[i-1] * rProd;
            //out[i] = ((i != 0) ? lProd[i-1] : 1) * rProd;
            rProd *= nums[i];
        }
        return out;
    }
};
