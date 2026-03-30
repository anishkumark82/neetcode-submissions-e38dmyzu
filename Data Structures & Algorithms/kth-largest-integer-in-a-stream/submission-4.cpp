class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {

        nK = k;
        for(auto &n: nums)
            pq.push(n);
        while(pq.size() > nK)
            pq.pop();
    }
    
    int add(int val) {
        if(pq.size() < nK)
            pq.push(val);
        else if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();        
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int nK;
};
