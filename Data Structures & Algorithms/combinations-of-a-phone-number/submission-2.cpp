class Solution {
private:
    void _dfs(int i, string &d, string &cur, vector<string> &out)
    {
        if(i == d.length())
        {
            out.push_back(cur);
            return;
        }

        auto letters = dStrMap[d[i]];
        for(auto &ch : letters)
        {
            cur += ch;
            _dfs(i+1, d, cur, out);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        vector<string> out;
        string cur;
        _dfs(0, digits, cur, out);
        return out;
    }
    unordered_map<char,string> dStrMap{{'0',""}, 
                                       {'1', ""}, 
                                       {'2', "abc"},
                                       {'3', "def"},
                                       {'4', "ghi"},
                                       {'5', "jkl"},
                                       {'6', "mno"},
                                       {'7', "pqrs"},
                                       {'8', "tuv"},
                                       {'9', "wxyz"}
                                       };
};
