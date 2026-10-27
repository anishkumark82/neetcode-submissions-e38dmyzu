class Solution {
    //'({[]}){}'
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if(match.count(ch))
            {
                if(!st.empty() && match[ch] == st.top())
                    st.pop();   
                else 
                    return false;
            }
            // any other character ignore
        }
        return st.empty();

    }
    unordered_map<char, char> match{{')', '('}, {'}', '{'}, {']', '['}};
};
