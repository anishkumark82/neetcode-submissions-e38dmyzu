class Solution {
private:
    bool _dfs(int i, int cnt, string &s, vector<vector<int>> &dp)
    {
        if(i == s.size())
            return (cnt == 0);

        if(dp[i][cnt] != -1)
            return dp[i][cnt];

        bool isValid = false;

        if(s[i] == '(')
            isValid = _dfs(i+1, cnt+1, s, dp);
        else if(s[i] == ')')
        {
            if(cnt > 0)
                isValid = _dfs(i+1, cnt-1, s, dp);
            // else it will be false;
        }
        else // s[i] = '*'
        {
            isValid = _dfs(i+1, cnt+1, s, dp); // Store as '('
            if(!isValid && cnt > 0) //  Store as ')'
                isValid = _dfs(i+1, cnt-1, s, dp);
            if(!isValid) // skip
                isValid = _dfs(i+1, cnt, s, dp);
        }
        dp[i][cnt] = (isValid) ? 1 : 0;
        return isValid;
    }
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return _dfs(0, 0, s, dp);
    }
};
