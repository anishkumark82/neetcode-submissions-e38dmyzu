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
    bool operator()(const Interval &i1, const Interval &i2) const {
        return (i1.start == i2.start) ? i1.end < i2.end : i1.start < i2.start;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // Create a min Heap storing the end_time
        // Remove the minHeap top if it is less than the next start_time.
        // Keep track of the max size of the heap. This will give the minNumber of rooms required.
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(intervals.begin(), intervals.end(), customSort());
        int minRooms = 0;
        for(auto &i : intervals)
        {
            while(!minHeap.empty() && minHeap.top() <= i.start) // The future meetings are all after the meeting in min heap
                minHeap.pop();
            minHeap.push(i.end);

            minRooms = max(minRooms, static_cast<int>(minHeap.size()));
        }
        return minRooms;
    }
};
