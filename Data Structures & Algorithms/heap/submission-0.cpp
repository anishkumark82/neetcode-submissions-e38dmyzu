class MinHeap {
public:
    MinHeap() {
        mHeap.clear();
        mHeap.push_back(0);
    }

    void perculateUp()
    {
        int i = mHeap.size()-1;
        int parent = i/2;

        while(parent > 0)
        {
            // Assuming min heap
            if(mHeap[i] < mHeap[parent])
                swap(mHeap[i], mHeap[parent]);
            else
                break;
            i = parent;
            parent = i/2;
        }
    }

    void perculateDown(int cur)
    {
        int left = 2 * cur;
        int right = 2 * cur + 1;

        while(left < mHeap.size())
        {
            int minIdx = (mHeap[cur] > mHeap[left]) ? left : cur;
            minIdx = (right < mHeap.size() && mHeap[minIdx] > mHeap[right]) ? right : minIdx;
            if(minIdx != cur)
            {
                swap(mHeap[cur], mHeap[minIdx]);
                cur = minIdx;
                left = 2 * cur;
                right = 2 * cur + 1;
            }
            else
                break;
        }
    }

    bool isEmpty()
    {
        return mHeap.size() == 1;
    }

    void push(int val) {
        mHeap.push_back(val);
        if(mHeap.size() == 2)
            return;
        
        // perculate up
        perculateUp();
    }

    int pop() {
        if (isEmpty())
            return -1;
        
        int res = mHeap[1];
        if(mHeap.size() == 2)
        {
            mHeap.pop_back();
            return res;
        }

        swap(mHeap[1], mHeap.back());
        mHeap.pop_back(); // delete the current element.

        perculateDown(1);
        return res;
    }

    int top() {
        if(isEmpty())
            return -1;
        return mHeap[1];
    }

    void heapify(const vector<int>& arr) {
        MinHeap();
        mHeap.insert(mHeap.end(), arr.begin(), arr.end());
        for(int i = mHeap.size()/2; i > 0; --i)
            perculateDown(i);
    }
    vector<int> mHeap;
};
