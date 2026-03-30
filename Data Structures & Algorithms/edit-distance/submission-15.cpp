class Solution {
private:
    int _dfs(int i, int j, string &w1, string &w2, vector<vector<int>> &dp)
    {
        if(j == w2.size() && i == w1.size())
            return 0;
        
        if(j == w2.size()) // delete remaining characters in w1
            return w1.size()-i;
        
        if(i == w1.size()) // insert remaining characters in w1
            return w2.size()-j;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int minOp = 0;
        if(w1[i] == w2[j])
            minOp = _dfs(i+1, j+1, w1, w2, dp);
        else
        {
            // delete a element in w1
            minOp = 1 + _dfs(i+1, j, w1, w2, dp);
            // insert a element in w1
            minOp = min(minOp, 1 + _dfs(i, j+1, w1, w2, dp));
            // Replace an element
            minOp = min(minOp, 1 + _dfs(i+1, j+1, w1, w2, dp));
        }
        dp[i][j] = minOp;
        return minOp;
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>dp(m+1, 0);
        vector<int>newDp(m+1, 0);
        //for(auto r = 0; r <= n; ++r)
        dp[0] = 0;
        //newDp[0] = 1;
        for(auto c = 0; c <= m; ++c)
            dp[c] = c;
        
        for(int r = 1; r <= n; ++r)
        {
            newDp[0] = r;
            for(int c = 1; c <= m; ++c)
            {
                if(word1[r-1] == word2[c-1])
                    newDp[c] = dp[c-1];
                else
                {
                    // insert
                    newDp[c] = 1 + newDp[c-1];
                    // delete
                    newDp[c] = min(newDp[c], 1 + dp[c]);
                    // replace
                    newDp[c] = min(newDp[c], 1 + dp[c-1]);
                }
            }
            swap(dp, newDp);
        }
        return dp[m];
        //return _dfs(0,0, word1, word2, dp);
    }
};
