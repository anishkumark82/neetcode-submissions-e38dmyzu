class Solution {
vector<vector<int>> explore{{1,0}, {-1,0}, {0,1}, {0,-1}};
private:
    // O(m*n)(m+n)
    int _dfs(vector<vector<int>> &matrix, int r, int c, 
             int rMax, int cMax, int prev, vector<vector<bool>> &visited, vector<vector<int>> &dp)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;
        if(!rInBounds || !cInBounds)
            return 0;
        
        if (visited[r][c])
            return 0;

        if(matrix[r][c] <= prev)
            return 0;

        if(dp[r][c] != -1)
            return dp[r][c];

        visited[r][c] = true;
        int maxPath = 0;
        for(auto &e : explore)
            maxPath = max(maxPath, 1 + _dfs(matrix, r+e[0], c+e[1], rMax, cMax, matrix[r][c], visited, dp));
        dp[r][c] = maxPath;
        visited[r][c] = false;
        return maxPath;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxLen = 0;
        int rMax = matrix.size();
        int cMax = matrix[0].size();
        vector<vector<int>> dp(rMax,vector<int>(cMax, -1));
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
            {
                vector<vector<bool>> visited(rMax,vector<bool>(cMax, false));
                maxLen = max(maxLen, _dfs(matrix, r, c, rMax, cMax, -1, visited, dp));
            }
        return maxLen;
    }
};
