class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        nS.push(val);
        int minVal = minS.empty() ? val : min(minS.top(), val);
        minS.push(minVal);
    }
    
    void pop() {
        if(!nS.empty())
        {
            nS.pop();
            minS.pop();
        }
    }
    
    int top() {
        return nS.top();
    }
    
    int getMin() {
        return minS.top();
    }
    private:
        stack<int> nS;
        stack<int> minS;
};
