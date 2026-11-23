class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Always add to the leftMaxHeap.
        leftMaxHeap.push(num);

        // Check if the left top <= right top
        if(!rightMinHeap.empty()) // Left will not be empty
        {
            if(leftMaxHeap.top() > rightMinHeap.top())
            {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }
        }

        if(leftMaxHeap.size() > rightMinHeap.size() + 1)
        {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(rightMinHeap.size() > leftMaxHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
        // else dont do anything            
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()) // even
            return (static_cast<double>(leftMaxHeap.top()) + rightMinHeap.top()) / 2; 
        return leftMaxHeap.top();
    }
    // left maxHeap - access middle element from left in O(log n)
    priority_queue<int> leftMaxHeap{};

    // right minHeap -- log n to access the middle element from right
    priority_queue<int, vector<int>, greater<int>> rightMinHeap{};
};
