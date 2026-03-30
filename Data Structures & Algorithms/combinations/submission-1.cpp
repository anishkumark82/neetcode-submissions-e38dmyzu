class Solution {
private:
    void helper(int i, int n, int k, vector<int> &cur, vector<vector<int>> &out)
    {
        if(cur.size() == k)
            out.push_back(cur);

        if(i == n+1)
            return;
        
        for(auto j = i; j < n+1; ++j)
        {
            cur.push_back(j);
            helper(j+1, n, k, cur, out);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> out;
        helper(1, n, k, cur, out);
        return out;
    }
};