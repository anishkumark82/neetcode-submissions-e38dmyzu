class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> out;
        for(auto &i : intervals)
        {
            if(out.size() != 0 && i[0] <= out.back()[1])
                out.back()[1] = max(out.back()[1], i[1]);
            else
                out.push_back(i);
        }
        return out;
    }
};
