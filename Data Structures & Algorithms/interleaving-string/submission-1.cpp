class Solution {
private:
    bool _dfs(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &dp)
    {
        if(k == s3.size())
            return true;
        
        if(dp[i][j] != -1)
            return (dp[i][j]);

        bool valid = false;
        if(i != s1.size() && s1[i] == s3[k])
            valid = _dfs(i+1, j, k+1, s1, s2, s3, dp);
        
        if(!valid && j != s2.size() && s2[j] == s3[k])
            valid = _dfs(i, j+1, k+1, s1, s2, s3, dp);

        dp[i][j] = valid;        
        return valid;

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return _dfs(0,0,0, s1, s2, s3, dp);
    }
};