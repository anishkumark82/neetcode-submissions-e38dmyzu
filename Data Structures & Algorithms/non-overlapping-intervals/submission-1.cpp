class hashFunc{
    size_t operator()(const pair<int,int> &p) const{
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // ascending order
        // keep track of the minE
        int minE = -60000;
        int cnt = 0;
        for(auto &i : intervals)
        {
            if(i[0] < minE) // Detect Overlaps
            {
                cnt++;
                minE = min(minE, i[1]);
            }
            else
                minE = i[1];
        }
        return cnt;
    }
};
