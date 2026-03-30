class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
            // corner cases
            // intervals is empty
            if(intervals.size() == 0)
                return {newInterval};
            
            vector<vector<int>> out;
            // if newInterval is smaller than Interval[0][0]
            if(newInterval[1] < intervals[0][0])
            {
                out.push_back(newInterval);
                out.insert(out.end(), intervals.begin(), intervals.end());
                return out;
            }
                
            // if newInterval is greater than Interval.bak()[1]
            if(intervals.back()[1] < newInterval[0])
            {
                out.insert(out.end(), intervals.begin(), intervals.end());
                out.push_back(newInterval);
                return out;
            }

            // track if the newInterval is inserted
            bool inserted = false;
            // the interval is inbetween
            for(auto i = 0; i < intervals.size(); ++i)
            {
                if(!inserted)
                {
                    // Negative case
                    if(newInterval[0] > intervals[i][1])
                        out.push_back(intervals[i]);
                    // newInterval[0] < intervals[i][0] // No overlap
                    else 
                    {
                        if(newInterval[0] < intervals[i][0] && newInterval[1] < intervals[i][0])
                        {
                            out.push_back(newInterval);
                            out.push_back(intervals[i]);
                        }
                        else if(newInterval[0] <= intervals[i][0])
                        {   // && newInterval[1] <= intervals[i][1])
                            // && newInterval[1] > intervals[i][1]
                            out.push_back({newInterval[0], max(intervals[i][1], newInterval[1])});
                        }
                        else if(newInterval[0] >= intervals[i][0] )
                        {
                            // && newInterval[1] <= intervals[i][1]
                            // && newInterval[1] > intervals[i][1]
                            out.push_back({intervals[i][0], max(newInterval[1], intervals[i][1])});
                        }                        
                        inserted = true;
                    }
                }
                else
                {
                    if(intervals[i][0] <= out.back()[1])
                        out.back()[1] = max(intervals[i][1], out.back()[1]);
                    else
                        out.push_back(intervals[i]);
                }
            }
            return out;
        }
};
