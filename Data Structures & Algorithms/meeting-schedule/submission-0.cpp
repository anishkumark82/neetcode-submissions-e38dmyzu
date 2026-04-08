/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

struct customSort{
    bool operator()(const Interval &i1, const Interval &i2) const
    {
        if (i1.start == i2.start) return i1.end < i2.end;
        return i1.start < i2.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), customSort());
        int lastEnd = 0;
        for(auto &i : intervals)
        {
            if(i.start < lastEnd)
                return false;
            lastEnd = i.end;
        }
        return true;
    }
};
