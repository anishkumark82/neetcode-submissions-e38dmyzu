class Solution {
public:
    bool isValid(string s) {
        stack <char> vS;
        for(auto &ch :s)
        {
            if(bMap.count(ch))
            {
                if(vS.empty() || bMap[ch] != vS.top())
                    return false;
                vS.pop();
            }
            else
                vS.push(ch);
        }
        return vS.empty();
    }
private:
    unordered_map<char, char>bMap = {{')', '('}, {'}', '{'}, {']', '['}};
};
