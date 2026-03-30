class Solution {
    // T - O(n*m), S - O(n*m)
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size();
        int M = text2.size();
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

        for(auto r = 1; r <= N; ++r)
            for(auto c = 1; c <=M; ++c)
            {
                if(text1[r-1] == text2[c-1])
                    dp[r][c] = 1 + dp[r-1][c-1];
                else
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
            }
        return dp.back().back();
    }
};
