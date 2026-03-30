class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Create a maxHeap of size K
        // of the value > top of maxHeap ignore.
        vector<vector<int>> out;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < points.size(); ++i)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (pq.size() < k)
                pq.push({dist, i});
            else if (pq.top().first > dist)
            {
                pq.pop();
                pq.push({dist, i});
            }
        }
        while(pq.size())
        {
            out.push_back(points[pq.top().second]);
            pq.pop();
        }
        return out;
    }
};
