class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto &n : nums) // n log n
            minHeap.push(n);

        while(minHeap.size() > k) // n-k log n
            minHeap.pop();
        nK = k;
    }
    int add(int val) {
        if(minHeap.size() == nK && val < minHeap.top())
            return minHeap.top();

        minHeap.push(val);
        while(minHeap.size() > nK) // n-k log k
            minHeap.pop();
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int nK;
};
