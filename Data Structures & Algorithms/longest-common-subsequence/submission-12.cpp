class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int maxLen = 0;
        int row = text1.size();
        int col = text2.size();

        if(row < col)
            return longestCommonSubsequence(text2, text1);
        
        //vector<vector<int>>dp(row+1, vector<int>(col+1, 0));
        vector<int>dp(col+1, 0);
        vector<int>newDp(col+1, 0);
        for(int r = row-1; r >=0; --r)
        {
            for(int c = col-1; c>=0; --c)
            {
                if(text1[r] == text2[c])
                    newDp[c] = 1 + dp[c+1];
                else
                    newDp[c] = max(dp[c], newDp[c+1]);
            }
            dp = newDp;
        }
        return dp[0];
    }
};
