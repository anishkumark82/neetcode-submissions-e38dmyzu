class Solution {
    int _dfs(string &t1, string &t2, int i, int j, vector<vector<int>>&dp)
    {
        if(i == t1.size() || j == t2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int len = 0;
        if(t1[i] == t2[j])
            len = 1 + _dfs(t1, t2, i+1, j+1, dp);
        else
        {
            len = max(len, _dfs(t1, t2, i+1, j, dp));
            len = max(len, _dfs(t1,t2, i, j+1, dp));
        }
        dp[i][j] = len;
        return len;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int maxLen = 0;
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return _dfs(text1, text2, 0,0, dp);
    }
};
