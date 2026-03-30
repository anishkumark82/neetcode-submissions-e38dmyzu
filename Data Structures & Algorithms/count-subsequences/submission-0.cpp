class Solution {
    int _dfs(int i1, int i2, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i2 == t.size())
            return 1;
        
        if(i1 == s.size())
            return 0;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];

        int numSeq = 0;
        // elements match
        if(s[i1] == t[i2])
        {
            numSeq = _dfs(i1+1, i2+1, s, t, dp);
            numSeq += _dfs(i1+1, i2, s, t, dp); // Could find another matching entry within s for cur location of t
        }
        else
            numSeq = _dfs(i1+1, i2, s, t, dp);
        dp[i1][i2] = numSeq;
        return numSeq;            
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        if(s.size() < t.size())
            return 0;
        return _dfs(0, 0, s, t, dp);
    }
};
