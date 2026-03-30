using INT_PAIR = pair<int,int>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Create a maxHeap of size k.
        // [dist, idx]
        priority_queue<INT_PAIR> maxHeap;
        //O(nlogk)
        for(auto i = 0; i < points.size(); ++i)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, i});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        // O(k log k)
        vector<vector<int>> out;
        while(!maxHeap.empty())
        {
            int i = maxHeap.top().second;
            maxHeap.pop();
            out.push_back(points[i]);
        }
        return out;
    }
};
