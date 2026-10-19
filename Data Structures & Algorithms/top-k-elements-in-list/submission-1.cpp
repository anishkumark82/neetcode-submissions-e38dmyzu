class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cntMap;
        // MinHeap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> out;

        for(auto &n : nums)
            cntMap[n]++;
        for(auto &itr : cntMap)
        {
            minHeap.push({itr.second, itr.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }
        while(minHeap.size())
        {
            out.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return out;
    } 
};
