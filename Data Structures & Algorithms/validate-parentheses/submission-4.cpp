class Solution {
private:
    unordered_map<char,char> charMap{{'}','{'}, {']', '['}, {')', '('}};
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto &ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            
            else if(charMap.find(ch) != charMap.end())
            {
                if(st.empty() || st.top() != charMap[ch]) 
                    return false;
                st.pop();
            }
        }

        return (st.empty());
    }
};
