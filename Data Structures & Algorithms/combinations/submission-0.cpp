class Solution {
private:
    void helper(int i, int n, int k, vector<int> &cur, vector<vector<int>> &out)
    {
        if(cur.size() == k)
        {
            out.push_back(cur);
            return;
        }

        // reached end but did not full-fill the condition
        if(i == n+1)
            return;

        cur.push_back(i);
        helper(i+1, n, k, cur, out);
        cur.pop_back();
        helper(i+1, n, k, cur, out);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> out;

        helper(1, n, k, cur, out);
        return out;
    }
};