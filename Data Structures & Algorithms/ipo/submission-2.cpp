class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        multimap<int,int> capMap;
        for(auto i = 0; i < capital.size(); ++i) // n log n
            capMap.insert({capital[i], profits[i]});
        int i = 0; 
        int curProfit = w;
        priority_queue<int> maxHeap;
        auto itr = capMap.begin();
        for(auto i = 0; i < k; ++i)
        {
            for(;itr != capMap.end() && itr->first <= curProfit; ++itr)
                maxHeap.push(itr->second);

            if(maxHeap.empty())
                break;

            curProfit += maxHeap.top();
            maxHeap.pop();
        }
        return curProfit;
    }
};