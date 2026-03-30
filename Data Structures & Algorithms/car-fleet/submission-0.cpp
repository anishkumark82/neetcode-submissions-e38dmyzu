class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Monotonic stack problem -- We need to keep track of the largest bottleneck at each point.
        // 1. Sort the arry in the descending position order from target.
        vector<pair<int,int>> dist(position.size());
        for(int i = 0; i < position.size(); ++i)
            dist[i] = {position[i], speed[i]};
        sort(dist.begin(), dist.end(), greater<pair<int,int>>());

        stack<double> monoSt;
        for(auto &d : dist)
        {
            double t = (static_cast<double>(target)-d.first)/d.second;
            if(monoSt.empty() || monoSt.top() < t)
                monoSt.push(t);
        }
        return monoSt.size();
    }
};
