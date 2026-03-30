class MedianFinder {
public:
    MedianFinder() {
        // Two Heap solution
    }
    
    // LeftMaxHeap :    2, 1
    // Right Min Heap : 3 

    void addNum(int num) {
        // Add the number to the leftMaxHeap always
        leftMaxHeap.push(num);

        if(!leftMaxHeap.empty() && !rightMinHeap.empty())
        {
            if(leftMaxHeap.top() > rightMinHeap.top())
            {
                int val = leftMaxHeap.top();
                rightMinHeap.push(val);
                leftMaxHeap.pop();
            }
        }

        // Check if both left and right heaps dont differ by more than 1
        if(leftMaxHeap.size() > rightMinHeap.size()+1)
        {
            int val = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(val);
        }
        else if(rightMinHeap.size() > leftMaxHeap.size()+1)
        {
            int val = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(val);
        }
        // Else leave it as it is.
    }
    
    double findMedian() {
        int heapSize = (leftMaxHeap.size()+ rightMinHeap.size());
        if( heapSize % 2 != 0)
        {
            if(leftMaxHeap.size() > rightMinHeap.size())
                return leftMaxHeap.top();
            return rightMinHeap.top();
        }
        return (static_cast<double>(leftMaxHeap.top()) + rightMinHeap.top()) / 2;
    }
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
};
