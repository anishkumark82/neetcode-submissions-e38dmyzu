class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(minS.empty() || minS.top() > val)  
            minS.push(val);
        else
            minS.push(minS.top());
    }
    
    void pop() {
        s1.pop();
        minS.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return minS.top();
    }
    stack<int>s1;
    stack<int>minS;
};
