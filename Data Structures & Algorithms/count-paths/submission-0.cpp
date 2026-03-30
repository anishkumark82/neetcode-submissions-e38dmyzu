class Solution {
private:
    int _explore(int r, int c, int m, int n, vector<vector<int>>memo)
    {
        if(r >= m || c >= n)
            return 0;
        
        if(memo[r][c] != -1)
            return memo[r][c];
        
        memo[r][c] = _explore(r+1, c, m, n, memo) + _explore(r, c+1, m, n, memo);
        return memo[r][c];
    }
public:
    
    // Via memoization
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        memo[m-1][n-1] = 1;
        return _explore(0,0,m,n, memo);    
    }
};
