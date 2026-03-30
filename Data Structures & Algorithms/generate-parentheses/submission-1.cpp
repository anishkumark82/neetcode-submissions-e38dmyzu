class Solution {
private:
    void _dfs(int i, int j, int n, string cur, vector<string> &out)
    {
        if(i == n && j == n)
        {
            out.push_back(cur);
            return;
        }

        if(i != n)
            _dfs(i+1, j, n, cur+'(', out);
        
        if(j < i)
            _dfs(i, j+1, n, cur+')', out);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string cur;

        _dfs(0, 0, n, cur, out);
        return out;
    }
};
