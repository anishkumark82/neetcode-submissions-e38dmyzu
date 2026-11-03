class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minS.empty()|| minS.top() > val)
            minS.push(val);
        else
            minS.push(minS.top());
    }
    
    void pop() {
        if(!s.empty())
        {
            s.pop();
            minS.pop();
        }
    }
    
    int top() {
        if(!s.empty())
            return s.top();
        return INT_MIN;
    }
    
    int getMin() {
        if(!s.empty())
            return minS.top();
        return INT_MIN;
    }
    stack<int> s;
    stack<int> minS;
};
