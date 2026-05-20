class Solution {
// ops=["1","2","+","C","5","D"]
// s - 1, 2, 5,
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int curSum = 0;
        for(auto &op : operations)
        {
            if(op == "+")
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                int op3 = op1 + op2;
                s.push(op1);
                s.push(op2);
                s.push(op3);
            }
            else if(op == "C")
            {
                curSum -= s.top();
                s.pop();
            }
            else if(op == "D")
                s.push(s.top()*2);
            else
                s.push(stoi(op));            

            if(op != "C")
                curSum += s.top();                
        }
        return curSum;        
    }
};