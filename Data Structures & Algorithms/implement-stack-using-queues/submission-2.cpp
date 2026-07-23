class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> &sQ1 = Q1.empty() ? Q1 : Q2;
        queue<int> &sQ2 = Q1.empty() ? Q2 : Q1;
        sQ1.push(x);
        while(!sQ2.empty())
        {
            sQ1.push(sQ2.front());
            sQ2.pop();
        }
    }
    
    int pop() {
        int x = -1;
        if(!Q1.empty())
        {
            x = Q1.front();
            Q1.pop();
        }
        else if(!Q2.empty())
        {
            x = Q2.front();
            Q2.pop();
        }
        
        return x;
    }
    
    int top() {
        if(!Q1.empty())
            return Q1.front();
        if(!Q2.empty())
            return Q2.front();
    }
    
    bool empty() {
        return(Q1.empty() && Q2.empty());
    }
    queue<int> Q1;
    queue<int> Q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */