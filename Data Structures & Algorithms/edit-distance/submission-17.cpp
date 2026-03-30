class Solution {
private:
    int _dfs(int i1, int i2, string& w1, string& w2, vector<vector<int>> &dp)
    {
        if(i2 == w2.size())
            return w1.size()-i1; // Remove remaining w1 elements

        if(i1 == w1.size()) // Insert the remaining w2 elements
            return w2.size()-i2;
        
        if(dp[i1][i2] != -1)
            dp[i1][i2];

        int minOp = 0;
        if(w1[i1] == w2[i2])
            minOp = _dfs(i1+1, i2+1, w1, w2, dp);
        else
        {
            // 3 Options.
            // 3.1 Insert matching character
            minOp = _dfs(i1, i2+1, w1, w2, dp);
            // 3.2 Delete current character
            minOp = min(minOp, _dfs(i1+1, i2, w1, w2, dp));
            // 3.3 Replace current character 
            minOp = min(minOp, _dfs(i1+1, i2+1, w1, w2, dp));
            minOp += 1;
        }
        dp[i1][i2] = minOp;
        return minOp;
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(auto r = 1; r <= n; ++r)
            dp[r][0] = r;
        
        for(auto c = 1; c <= m; ++c)
            dp[0][c] = c;

        for(auto r = 1; r <= n; ++r)
            for(auto c = 1; c <= m; ++c)
            {
                if(word1[r-1] == word2[c-1])
                    dp[r][c] = dp[r-1][c-1];
                else
                    dp[r][c] = 1+ min(min(dp[r][c-1], dp[r-1][c]), dp[r-1][c-1]);
            }

        return dp.back().back();
    }
};
