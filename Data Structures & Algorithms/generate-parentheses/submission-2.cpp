class Solution {
    // n = 1;
private:
    void _dfs(int l, int r, int n, string &cur, vector<string> &out)
    {
        if(l == n && r == n)
        {
            out.push_back(cur);
            return;
        }

        if(l > n)
            return;

        cur += '(';
        _dfs(l+1, r, n, cur, out);
        cur.pop_back();
        
        if(r < l)
        {
            cur += ')';
            _dfs(l, r+1, n, cur, out);
            cur.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string cur;
        _dfs(0, 0, n, cur, out);
        return out;
    }
};
