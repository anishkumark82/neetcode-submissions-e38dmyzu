class Solution {
private:
    void _dfs(int i, int n, int k, 
              vector<int> &cur, 
              vector<vector<int>> &out)
    {
        if(cur.size() == k)
        {
            out.push_back(cur);
            return;
        }
        if(i > n)
            return;
        
        // path with current node included
        cur.push_back(i);
        _dfs(i+1, n, k, cur, out);
        cur.pop_back();

        // path without current node included
        _dfs(i+1, n, k, cur, out);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur{};
        vector<vector<int>>out;

        _dfs(1, n, k, cur, out);
        return out;
    }
};