class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto &n : nums)
        {
            minPQ.push(n);
            if(minPQ.size() > k)
                minPQ.pop();
        }
        mK = k;
    }
    
    int add(int val) {
        minPQ.push(val);

        while(minPQ.size() > mK)
            minPQ.pop();
        
        return minPQ.top();
    }
    priority_queue<int, vector<int>, greater<int>> minPQ;
    int mK;
};
