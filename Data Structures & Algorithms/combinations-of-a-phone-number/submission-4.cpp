class Solution {
private:
 public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};

        vector<string> res{""};

        for(auto &d : digits)
        {
            vector<string> tmp{};
            for(auto &curStr : res)
            {
                for(auto &ch : dStrMap[d])
                    tmp.push_back(curStr+ch);
            }
            res = tmp;
        }
        return res;
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
