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
        
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return _dfs(0,0, s,t, dp);
    }
};
