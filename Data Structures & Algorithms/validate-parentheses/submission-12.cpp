class Solution {

public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch : s)
            if(bMap.count(ch))
                if(st.empty() || st.top() != bMap[ch])
                    return false;
                else
                    st.pop();
            else
                st.push(ch);

        return st.empty();
    }
private:
    unordered_map<char, char> bMap = {{')', '('}, {'}', '{'}, {']', '['}};
};
