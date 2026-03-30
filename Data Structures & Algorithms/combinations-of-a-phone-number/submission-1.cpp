class Solution {
    void helper(int i, string &digits, string &cur, vector<string> &out)
    {
        if(i == digits.size())
        {
            out.push_back(cur);
            return;
        }
        string iStr = dMap[digits[i]];
        for(auto j = 0; j < iStr.length(); ++j)
        {
            cur += iStr[j];
            helper(i+1, digits, cur, out);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> out;
        string cur;    
        helper(0, digits, cur, out);
        return out;
    }
    unordered_map<char, string> dMap = { {'2' , "abc"}, {'3' , "def"},  {'4', "ghi"}, {'5', "jkl"}, 
                                          {'6' , "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
};
