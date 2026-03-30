class Solution {
private:
    int _dfs(int i, string s, vector<int> &dp)
    {
        if( i == s.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];

        int total = 0;
        if(s[i] >= '1' && s[i] <= '9')
            total = _dfs(i+1, s, dp);
        else
            return 0;
        if((i+1 < s.size()) && 
           ((s[i] == '1' && s[i+1] <= '9') || (s[i] == '2' && s[i+1] <= '6')))
            total += _dfs(i+2, s, dp);
        dp[i] = total;
        return total;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return _dfs(0,s, dp);
    }
};
