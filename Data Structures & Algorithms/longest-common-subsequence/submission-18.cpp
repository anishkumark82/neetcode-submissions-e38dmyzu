class Solution {
private:
    int _dfs(int i1, int i2, string &text1, string &text2, 
             vector<vector<int>> &dp)
    {
        if(i1 == text1.size() || i2 == text2.size())
            return 0;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];

        if(text1[i1] == text2[i2])
            dp[i1][i2] = 1 + _dfs(i1+1, i2+1, text1, text2, dp);
        else
            dp[i1][i2] = max(_dfs(i1+1, i2, text1, text2, dp), 
                      _dfs(i1, i2+1, text1, text2, dp)); 
        return dp[i1][i2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m+1, 0);
        vector<int> newDp(m+1, 0);
        for(auto r = 1; r <= n; ++r)
        {    
            for(auto c = 1; c <= m; ++c)
            {
                if(text1[r-1] == text2[c-1])
                    newDp[c] = 1 + dp[c-1];
                else
                    newDp[c] = max(dp[c], newDp[c-1]);
            }
            swap(newDp, dp);
        }
        
        return dp.back();
    }
};
