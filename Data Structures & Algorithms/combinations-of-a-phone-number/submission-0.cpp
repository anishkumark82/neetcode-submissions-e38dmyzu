class Solution {
private:
    void _dfs(int i,  string& digit, string& cur, vector<string>& out)
    {
        if(i == digit.size())
        {
            out.push_back(cur);
            return;
        }
        string mapData = decode[digit[i] - '0'];
        for(auto &ch : mapData)
        {
            cur += ch;
            _dfs(i+1, digit, cur, out);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> out;
        string cur = "";
        _dfs(0, digits, cur, out);
        return out;
    }
private:
    vector<string> decode{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};     
};
