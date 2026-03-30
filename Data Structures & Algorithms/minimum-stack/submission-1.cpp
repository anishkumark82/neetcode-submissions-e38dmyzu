class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        S1.push(val);
        if(S2.empty())
            S2.push(val);
        else
            S2.push(min(val, S2.top()));
    }
    
    void pop() {
        if(!S1.empty())
        {
            S1.pop();
            S2.pop();
        }
    }
    
    int top() {
        return (!S1.empty()) ? S1.top() : -1;
    }
    
    int getMin() {
        return (!S1.empty()) ? S2.top() : -1;
    }
private:
    stack <int> S1;
    stack <int> S2;
};
