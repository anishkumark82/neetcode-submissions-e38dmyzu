class MyStack {
public:
    MyStack() {
    }
    
    void _pushQ(int x, queue<int> &Q1, queue<int> &Q2)
    {
        if(Q1.empty())
        {
            Q1.push(x);
            while(!Q2.empty())
            {
                Q1.push(Q2.front());
                Q2.pop();
            }
        }
    }
    void push(int x) {
        if(q1.empty())
            _pushQ(x, q1, q2);
        else
            _pushQ(x, q2,q1);
    }
    
    int pop() {
        int ret = -1;
        if(q1.empty() && q2.empty())
            return ret;
        
        if(q1.empty())
        {
            ret = q2.front();
            q2.pop();
            return ret;
        }
        ret = q1.front();
        q1.pop();
        return ret;
    }
    
    int top() {
        if(q1.empty() && q2.empty())
            return -1;
        
        if(q1.empty())
            return q2.front();

        return q1.front();
    }
    
    bool empty() {
       return (q1.empty() && q2.empty());     
    }
    queue<int>q1;
    queue<int>q2;
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */