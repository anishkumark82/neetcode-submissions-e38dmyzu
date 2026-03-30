class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lProduct(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
            lProduct[i] = lProduct[i-1] * nums[i-1];
        int rProduct = 1;
        for(int i = nums.size()-1; i >= 0; --i)
        {
            lProduct[i] *= rProduct;
            rProduct = rProduct * nums[i];
        }
        return lProduct;
    }
};
