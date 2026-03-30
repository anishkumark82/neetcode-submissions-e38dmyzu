class Solution {
private:
    int _dfs(int prev, int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        bool rInBounds = r >= 0 && r < matrix.size();
        bool cInBounds = c >= 0 && c < matrix[0].size();

        if(!rInBounds || !cInBounds || matrix[r][c] <= prev)
            return 0;
        
        if(dp[r][c] != -1)
            return dp[r][c];

        int val = matrix[r][c];
        int maxLen = 1 + _dfs(val, r+1, c, matrix, dp);
        maxLen = max(maxLen, 1 + _dfs(val, r-1, c, matrix, dp));
        maxLen = max(maxLen, 1 + _dfs(val, r, c-1, matrix, dp));
        maxLen = max(maxLen, 1 + _dfs(val, r, c+1, matrix, dp));
        dp[r][c] = maxLen;
        return maxLen;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxLen = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(auto r = 0; r < matrix.size(); ++r)
        {
            for(auto c = 0; c < matrix[0].size(); ++c)
            {
                int curLen = _dfs(-1, r,c, matrix, dp);
                maxLen = max(curLen, maxLen);
            }
        }
        return maxLen;
    }
};
