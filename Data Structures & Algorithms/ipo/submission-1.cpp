class customSort{
public:
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2)
    {
        return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, customSort> minHeap;
        priority_queue<int> maxHeap;

        int res = w;

        for(auto i = 0; i < profits.size(); ++i)
            minHeap.push({capital[i], profits[i]});
        
        
        for(auto i = 0; i < k; ++i)
        {
            while(!minHeap.empty() && minHeap.top().first <= res) // Should not be empty            
            {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if(maxHeap.empty())
                break;

            res += maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
    
};