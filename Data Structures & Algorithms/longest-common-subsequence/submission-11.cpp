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
        int row = text1.size();
        int col = text2.size();

        if(row < col)
            return longestCommonSubsequence(text2, text1);
        
        //vector<vector<int>>dp(row+1, vector<int>(col+1, 0));
        vector<int>dp(col+1, 0);
        vector<int>newDp(col+1, 0);
        for(int r = row-1; r >=0; --r)
        {
            for(int c = col-1; c>=0; --c)
            {
                if(text1[r] == text2[c])
                    newDp[c] = 1 + dp[c+1];
                else
                    newDp[c] = max(dp[c], newDp[c+1]);
            }
            dp = newDp;
        }
        return dp[0];
    }
};
