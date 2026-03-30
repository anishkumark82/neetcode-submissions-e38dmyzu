class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a minHeap of size k
        // assertion nums.size() >= k
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto &n : nums)
        {
            minHeap.push(n);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};
