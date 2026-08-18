class Solution {
private:
    int _dfs(string &t1, string &t2, int i1, int i2, vector<vector<int>> &dp)
    {
        if(i1 == t1.size() || i2 == t2.size())
            return 0;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if(t1[i1] == t2[i2])
            dp[i1][i2] = 1 + _dfs(t1, t2, i1+1, i2+1, dp);
        else
            dp[i1][i2] = max(_dfs(t1, t2, i1+1, i2, dp), 
                             _dfs(t1, t2, i1, i2+1, dp));
        return dp[i1][i2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        //return _dfs(text1, text2, 0, 0, dp);
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto r = 1; r <= m; ++r)
            for(auto c = 1; c <= n; ++c)
                if(text1[r-1] == text2[c-1])
                    dp[r][c] = 1 + dp[r-1][c-1];
                else
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
        return dp.back().back();
    }
};
