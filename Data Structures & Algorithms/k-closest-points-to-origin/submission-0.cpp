using PAIR = pair<double, vector<int>>;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PAIR, vector<PAIR>, greater<PAIR>> maxPQ; // Store value followed by co-ordinates

        for(auto &p : points)
        {
            double dist = sqrt((static_cast<double>(p[0]) * p[0]) + (static_cast<double>(p[1]) * p[1]));
            maxPQ.push({dist, p});
        }
        vector<vector<int>> out;
        for(auto i = 1; i <= k; ++i)
        {
            out.push_back(maxPQ.top().second);
            maxPQ.pop();
        }
        return out;
    }
};
