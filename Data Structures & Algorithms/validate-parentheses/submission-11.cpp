class Solution {
    unordered_map<char, char> bMap = {{']', '['} , {'}', '{'},{')', '('}};
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch : s)
            if(ch == '[' || ch == '{' || ch == '(')
                st.push(ch);
            else if(!st.empty() && (bMap[ch] == st.top()))
                st.pop();
            else
                return false;

        return (st.empty());
    }

};
