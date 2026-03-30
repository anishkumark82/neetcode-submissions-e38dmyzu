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
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return _dfs(0,0, word1, word2, dp);
    }
};
