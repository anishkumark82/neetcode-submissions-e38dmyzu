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
    
    // Via Tabulation or bottom up
    int uniquePaths(int m, int n) {
        vector<vector<int>> tab(m, vector<int>(n, -1));
        for(auto c = 0; c < n; ++c)
            tab[m-1][c] = 1;

        for(int r = m-2; r >= 0; --r)
            for(int c = n-1; c >= 0; --c)
            {
                tab[r][c] = tab[r+1][c];
                tab[r][c] += ((c < n-1) ? tab[r][c+1] : 0);
            }
        return tab[0][0];
    }
};
