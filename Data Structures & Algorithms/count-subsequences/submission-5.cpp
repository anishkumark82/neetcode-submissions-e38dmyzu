class Solution {
private: 
    int _dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(j == t.size())
            return 1;
        
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        // ignore current i
        int numPaths = _dfs(i+1, j, s, t, dp);

        // if s[i] == t[j]
        if(s[i] == t[j])
            numPaths += _dfs(i+1, j+1, s, t, dp);

        dp[i][j] = numPaths;
        return numPaths;
    }

public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size())
            return 0;
        int N = s.size();
        int M = t.size();
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        
        for(auto i = 0; i <= N; ++i)
            dp[i][0] = 1;

        for(auto i = 1; i <= N; ++i)
            for(auto j = 1; j <=M; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }

        return dp.back().back();
    }
};
