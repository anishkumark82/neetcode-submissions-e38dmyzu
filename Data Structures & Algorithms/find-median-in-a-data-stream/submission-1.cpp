class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) { // log n
        lMaxHeap.push(num);
        rMinHeap.push(lMaxHeap.top());
        lMaxHeap.pop();
        if(rMinHeap.size() > lMaxHeap.size())
        {
            lMaxHeap.push(rMinHeap.top());
            rMinHeap.pop();
        }
    }
    
    double findMedian() { // O(1)
        if(rMinHeap.size() == lMaxHeap.size())
            return ((static_cast<double>(rMinHeap.top()) + lMaxHeap.top()) / 2);
        else 
            return lMaxHeap.top();
    }
private:
    // Maintain a min heap and a max Heap.
    priority_queue<int> lMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rMinHeap;
};
