class Solution {
    // dfs -- 2^mn, O(m+n)
    // Memoization
private:
    int _dfs(int r, int c, int rMax, int cMax, vector<vector<int>> &memo)
    {
        if(r > rMax-1 || c > cMax-1)
            return 0;

        if(r == rMax-1 && c == cMax-1)
            return 1;

        if(memo[r][c] != -1)
            return memo[r][c];

        memo[r][c] = _dfs(r+1, c, rMax, cMax, memo) + _dfs(r, c+1, rMax, cMax, memo);
        return memo[r][c];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return _dfs(0, 0, m, n, memo);
    }
};
