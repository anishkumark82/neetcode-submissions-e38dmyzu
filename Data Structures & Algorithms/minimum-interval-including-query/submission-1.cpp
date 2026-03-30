class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> out(queries.size(), -1);
        sort(intervals.begin(), intervals.end());
        
        // Stores the indexes of values.
        unordered_map<int, vector<int>> qMap;
        for(int i = 0; i < queries.size(); ++i)
            qMap[queries[i]].push_back(i);
        
        sort(queries.begin(), queries.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int i = 0;
        vector<int> result;
        for(auto &q : queries)
        {
            // Keep inserting the {dist, end} of intervals whose start <= q & end >= q
            while(i < intervals.size() && intervals[i][0] <= q)
            {
                //if(intervals[i][1] < q)
                //    continue;

                int dist = intervals[i][1] - intervals[i][0] + 1 ;
                minHeap.push({dist, intervals[i][1]});
                i++;
            }

            // Is the top of the minHeap.end() is < q 
            while(!minHeap.empty() && minHeap.top().second < q)
                minHeap.pop();
            
            int minRange = (minHeap.empty()) ? -1 : minHeap.top().first;
            result.push_back(minRange);
           
        }

        for(int i = 0; i < queries.size(); ++i)
        {
            auto &v = qMap[queries[i]];
            for(auto &idx : v)
                out[idx] = result[i];
        }

        return out;
    }   
};
