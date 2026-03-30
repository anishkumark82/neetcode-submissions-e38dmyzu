class Solution {
    // T- O(n*m), S - O(n*m)
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
        if(s.size() < t.size())
            return 0;

        int N = s.size();
        int M = t.size();
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        for(auto r = 0; r <= N; ++r)
            dp[r][0] = 1;

        for(auto r = 1; r <= N; ++r)
            for(auto c = 1; c <=M; ++c)
            {
                dp[r][c] = dp[r-1][c];
                if(s[r-1] == t[c-1])
                    dp[r][c] += dp[r-1][c-1];
            }
        return dp.back().back();
    }
};
