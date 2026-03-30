class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];

        priority_queue<int> maxPQ(stones.begin(), stones.end());
        do
        {
            int s1 = maxPQ.top();
            maxPQ.pop();
            int diff = s1 - maxPQ.top();
            maxPQ.pop();
            if(diff != 0)
                maxPQ.push(diff);
        }while(maxPQ.size() > 1);
        return (maxPQ.size() == 0) ? 0 : maxPQ.top();
    }
};
