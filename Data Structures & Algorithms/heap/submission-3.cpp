class MinHeap {
    // Used for push() 
    void perculateUp(int i)
    {
        int p = i / 2; // [parent node]
        while(p > 0 &&  hp[p] > hp[i]) // minHeap so parent < child
        {
            swap(hp[i], hp[p]);
            i = p;
            p = i/2;
        }
    }
    // Used for pop() and heapify()
    void perculateDown(int i)
    {
        int l = 2 * i;
        while(l < hp.size())
        {
            int r = 2 * i + 1;
            int next = i;
            if(hp[i] > hp[l])
                next = l;

            if(r < hp.size() && hp[next] > hp[r])
                next = r;

            if(next == i)
                break;

            swap(hp[i], hp[next]);  
            i = next;
            l = 2 * i;
        }
    }
public:
    MinHeap() {
        hp.push_back(0); // Unused first slot
    }

    void push(int val) {
        hp.push_back(val);
        perculateUp(hp.size()-1);
    }

    int pop() {
        int rt = -1;
        if(hp.size() == 1)
            return rt;

        rt = hp[1];
        if(hp.size() == 2)
        {            
            hp.pop_back();
            return rt;
        }

        swap(hp[1], hp.back());
        hp.pop_back();
        perculateDown(1);        
        return rt;
    }

    int top() {
        if(hp.size() == 1)
            return -1;
        return hp[1];
    }

        
    void heapify(const vector<int>& arr) {
        //hp.assign(1, 0);
        hp.insert(hp.end(), arr.begin(), arr.end());
        for(int i = (hp.size()-1) / 2; i > 0; --i)
            perculateDown(i);
    }
    vector<int>hp;
};
