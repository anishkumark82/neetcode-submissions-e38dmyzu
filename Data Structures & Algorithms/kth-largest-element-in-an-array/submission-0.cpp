class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // keep a min Heap of size k
        priority_queue<int, vector<int>, greater<int>> minPQ(nums.begin(), nums.end());
        while(minPQ.size() > k)
            minPQ.pop();

        return minPQ.top();
    }
};
