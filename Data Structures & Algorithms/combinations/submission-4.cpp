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

        // starting with i try to form all possible k combinations
        for(auto j = i; j <= n; ++j)
        {
            cur.push_back(j);
            _dfs(j+1, n, k, cur, out);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur{};
        vector<vector<int>>out;
        _dfs(1, n, k, cur, out);
        return out;
    }
};