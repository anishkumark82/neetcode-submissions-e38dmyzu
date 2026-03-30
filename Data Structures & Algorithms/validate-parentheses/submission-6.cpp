class Solution {
public:
    
    bool isValid(string s) {
        if(s.size() % 2 != 0) // has to be even
            return false;

        for(auto &ch : s)
            if(ch == '{' || ch == '(' || ch == '[')
                St.push(ch);
            else if(!St.empty() && bMap[ch] == St.top())
                St.pop();
            else
                return false;
        return St.empty();
    }
private:
    unordered_map <char, char> bMap {
        {')', '('}, 
        {'}', '{'}, 
        {']', '['}
        };
    stack<char> St;
};
