class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        St.push(val);
        if(minSt.empty() || minSt.top() > val)
            minSt.push(val);
        else
            minSt.push(minSt.top());
    }
    
    void pop() {
        if(!St.empty())
        {
            St.pop();
            minSt.pop();
        }
    }
    
    int top() {
        return St.top();
    }
    
    int getMin() {
        return minSt.top();
    }
    stack<int> St;
    stack<int> minSt;
};
