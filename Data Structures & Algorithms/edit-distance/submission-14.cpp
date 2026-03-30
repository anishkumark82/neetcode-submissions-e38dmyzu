class Solution {
private:
    int _dfs(int i, int j, string &w1, string &w2, vector<vector<int>> &dp)
    {
        if(j == w2.size() && i == w1.size())
            return 0;
        
        if(j == w2.size()) // delete remaining characters in w1
            return w1.size()-i;
        
        if(i == w1.size()) // insert remaining characters in w1
            return w2.size()-j;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int minOp = 0;
        if(w1[i] == w2[j])
            minOp = _dfs(i+1, j+1, w1, w2, dp);
        else
        {
            // delete a element in w1
            minOp = 1 + _dfs(i+1, j, w1, w2, dp);
            // insert a element in w1
            minOp = min(minOp, 1 + _dfs(i, j+1, w1, w2, dp));
            // Replace an element
            minOp = min(minOp, 1 + _dfs(i+1, j+1, w1, w2, dp));
        }
        dp[i][j] = minOp;
        return minOp;
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(auto r = 0; r <= n; ++r)
            dp[r][0] = r;

        for(auto c = 0; c <= m; ++c)
            dp[0][c] = c;
        
        for(int r = 1; r <= n; ++r)
            for(int c = 1; c <= m; ++c)
            {
                if(word1[r-1] == word2[c-1])
                    dp[r][c] = dp[r-1][c-1];
                else
                {
                    // insert
                    dp[r][c] = 1 + dp[r][c-1];
                    // delete
                    dp[r][c] = min(dp[r][c], 1 + dp[r-1][c]);
                    // replace
                    dp[r][c] = min(dp[r][c], 1 + dp[r-1][c-1]);
                }
            }
        return dp[n][m];
        //return _dfs(0,0, word1, word2, dp);
    }
};
