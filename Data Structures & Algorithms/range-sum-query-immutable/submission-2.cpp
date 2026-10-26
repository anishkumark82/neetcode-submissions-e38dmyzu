class NumArray {
public:
    NumArray(vector<int>& nums) { // O(n) - 1 time
        prefixSum.resize(nums.size(), 0);
        prefixSum[0] = nums[0];
        for(auto i = 1; i < nums.size(); ++i)
            prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        int remove = (left == 0) ? 0 : prefixSum[left-1];
        return prefixSum[right] - remove;
    }
    vector<int> prefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */