class Solution {
private:
    int _dfs(int i, int j, int cur, string &s, string &t, vector<vector<int>> &dp)
    {
        if(j == t.size())
            return 1;

        // Termination Conditon
        if(i == s.size() || s.size()-i < t.size()-j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int numMatches = 0;
        // if match found
        if(s[i] == t[j])
            numMatches = _dfs(i+1, j+1, cur+1, s, t, dp);
        // No match found or also increment i to see other combinations.
        numMatches += _dfs(i+1, j, cur, s, t, dp);
        
        dp[i][j] = numMatches;
        return numMatches;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(auto r = 0; r < dp.size(); ++r)
            dp[r][m] = 1;

        for(int r = n-1; r >=0; --r)
            for(int c = m-1; c >= 0; --c)
            {
                if(s[r] == t[c])
                    dp[r][c] = dp[r+1][c+1];
                dp[r][c] += dp[r+1][c];
            }
        return dp[0][0];
    }
};
