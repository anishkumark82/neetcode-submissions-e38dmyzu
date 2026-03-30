class Solution {
private:
    bool _dfs(string &s, int i, int pIdx, string curStr, unordered_set<string> &wSet, 
                vector<vector<int>> &dp)
    {
        if(i == s.length())
            return pIdx == s.length()-1;
        
        if(dp[i][pIdx+1] != -1)
            return (dp[i][pIdx+1]);

        // Include the match
        curStr += s[i];
        bool valid = false;

        if(wSet.count(curStr)) // Match for cur String
            valid = _dfs(s, i+1, i, "", wSet, dp);
        
        if(!valid)
            valid = _dfs(s, i+1, pIdx, curStr, wSet, dp);
        dp[i][pIdx+1] = valid;
        return valid;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wSet{wordDict.begin(), wordDict.end()};
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return _dfs(s, 0, -1, "", wSet, dp);

    }
};
