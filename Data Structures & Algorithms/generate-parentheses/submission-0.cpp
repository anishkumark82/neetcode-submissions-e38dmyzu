class Solution {
private:
    void _dfs(int i, int j, int n, string &cur, 
            unordered_set<string> &out)
    {
        if(i == n && j == n)
        {
            out.insert(cur);
            return;
        }
        
        if(i != n)
        {
            cur += '(';
            _dfs(i+1, j, n, cur, out);
            cur.pop_back();
        }

        if(j < i)
        {
            cur += ')';
            _dfs(i, j+1, n, cur, out);
            cur.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        unordered_set <string> out;
        string cur = "";
        _dfs(0,0, n, cur, out);
        return {out.begin(), out.end()};
    }
};
