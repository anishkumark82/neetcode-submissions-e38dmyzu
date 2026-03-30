class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for(auto i = 1; i < k; ++i)
            maxHeap.pop();
        return maxHeap.top();

    }
};
