class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        // Min Heap of size k.
        mK = k;
        for(auto &n : nums)
        {
            minHp.push(n);
            if(minHp.size() > k)
                minHp.pop();
        }
    }
    
    int add(int val) {
        minHp.push(val);
        if(minHp.size() > mK)
            minHp.pop();
        return minHp.top();
    }
    priority_queue<int, vector<int>, greater<int>> minHp;
    int mK;
};
