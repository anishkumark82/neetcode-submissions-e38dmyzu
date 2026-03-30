class Solution {
private: // Time O(n * m) Space (m * n)
    int _dfs(int i1, int i2, string &t1, string &t2, vector<vector<int>> &memo)
    {
        if(i1 == t1.size() || i2 == t2.size()) // base case
            return 0;

        if(memo[i1][i2] != -1)
            return memo[i1][i2];        
        if (t1[i1] == t2[i2])
            memo[i1][i2] = 1 + _dfs(i1+1, i2+1, t1, t2, memo);
        else
            memo[i1][i2] = max(_dfs(i1+1, i2, t1, t2, memo), 
                               _dfs(i1, i2+1, t1, t2, memo));
        return memo[i1][i2];
    }    
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return _dfs(0, 0, text1, text2, memo);
    }
};
