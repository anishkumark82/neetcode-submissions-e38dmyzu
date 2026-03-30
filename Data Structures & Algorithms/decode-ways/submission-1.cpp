class Solution {
private:
    int _dfs(int i, string &s, vector<int> &dp)
    {
        if(i == s.length())
            return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // form a string with 1 character
        int cnt = _dfs(i+1, s, dp);
        // form strings with 2 characters
        if(i+1 != s.length() && 
            (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
            cnt += _dfs(i+2, s, dp);
        dp[i] = cnt;
        return cnt;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return _dfs(0, s, dp);
    }
};
