class Solution {
    // T - O(n*m), S - O(n*m)
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size();
        int M = text2.size();
        vector<int> prev(M+1, 0);
        vector<int> dp(M+1, 0);

        for(auto r = 1; r <= N; ++r)
        {
            for(auto c = 1; c <= M; ++c)
            {
                if(text1[r-1] == text2[c-1])
                    dp[c] = 1 + prev[c-1];
                else
                    dp[c] = max(prev[c], dp[c-1]);
            }
            swap(prev, dp);
        }
        return prev.back();
    }
};
