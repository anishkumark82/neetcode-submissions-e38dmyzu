class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) { // log n
        lMaxHeap.push(num);
        
        // Ensure the MinHeap and MaxHeap top always gives the middle value
        if(!rMinHeap.empty() && (lMaxHeap.top() > rMinHeap.top()))
        {
            rMinHeap.push(lMaxHeap.top());
            lMaxHeap.pop();
        }
        
        // Check if minHeap and MaxHeap differ by more than 2
        if(abs(rMinHeap.size() - lMaxHeap.size() > 1))
        {
            if(rMinHeap.size() > lMaxHeap.size())
            {
                lMaxHeap.push(rMinHeap.top());
                rMinHeap.pop();
            }
            else // lMaxHeap is greater 
            {
                rMinHeap.push(lMaxHeap.top());
                lMaxHeap.pop();
            }
        }
    }
    
    double findMedian() { // O(1)
        if(rMinHeap.size() == lMaxHeap.size())
            return ((static_cast<double>(rMinHeap.top()) + lMaxHeap.top()) / 2);
        else 
            return (rMinHeap.size() > lMaxHeap.size()) ? static_cast<double>(rMinHeap.top()) : 
                                                         static_cast<double>(lMaxHeap.top());
    }
private:
    // Maintain a min heap and a max Heap.
    priority_queue<int> lMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rMinHeap;
};
