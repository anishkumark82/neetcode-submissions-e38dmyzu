class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1)
        {
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            int diff = t1-t2;
            if(diff != 0)
                pq.push(diff);
        }
        return (pq.size() != 0) ? pq.top() : 0;    
    }
};
