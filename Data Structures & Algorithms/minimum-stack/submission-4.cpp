class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty())
            minS.push(val);
        else 
        {
            int minEle = (minS.top() >= val) ? val : minS.top();
            minS.push(minEle);
        }
        s1.push(val);
    }
    
    void pop() {
        if(s1.empty())
            return;
        
        s1.pop();
        minS.pop();
    }
    
    int top() {
        if(s1.empty())
            return -1;
        
        return s1.top();
    }
    
    int getMin() {
        if(s1.empty())
            return -1;
        return minS.top();
    }
    stack<int> s1;
    stack<int> minS;
};
