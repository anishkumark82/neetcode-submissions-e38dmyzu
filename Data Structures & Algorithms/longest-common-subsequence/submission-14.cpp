class Solution {
private:
    int _dfs(int i, int j, string& t1, string& t2, vector<vector<int>> &dp)
    {
        if(i == t1.length() || j == t2.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int maxLCS = 0;
        // When t1[i] == t2[j]
        if(t1[i] == t2[j])
            maxLCS = 1 + _dfs(i+1, j+1, t1, t2, dp);
        else // i and j dont match so we have 2 possible paths -- skip i and include j or include i and skip j
            maxLCS = max(_dfs(i, j+1, t1, t2, dp), _dfs(i+1, j, t1, t2, dp));
        dp[i][j] = maxLCS;
        return maxLCS;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int r = n-1; r >= 0; --r)
            for(int c = m-1; c >= 0; --c)
            {
                if(text1[r] == text2[c])
                    dp[r][c] = 1 + dp[r+1][c+1];
                else
                    dp[r][c] = max(dp[r+1][c], dp[r][c+1]);
            }
        return dp[0][0];
        //return _dfs(0, 0, text1, text2, dp);
    }
};
