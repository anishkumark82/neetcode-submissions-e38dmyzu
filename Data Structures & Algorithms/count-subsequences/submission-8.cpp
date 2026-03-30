class Solution {
private:
    int _dfs(int i, int j, int cur, string &s, string &t, vector<vector<int>> &dp)
    {
        if(cur == t.size())
            return 1;

        // Termination Conditon
        if(j == t.size() || s.size()-i < t.size()-j)
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
        vector<vector<int>>dp(s.size(), vector<int>(t.size(), -1));
        return _dfs(0, 0, 0, s, t, dp);    
    }
};
