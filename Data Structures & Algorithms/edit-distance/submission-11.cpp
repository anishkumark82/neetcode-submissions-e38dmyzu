class Solution {
    int _dfs(int i1, int i2, string &w1, string &w2, vector<vector<int>> &dp)
    {
        if(i1 == w1.size() && i2 == w2.size())
            return 0;
        
        if(i1 == w1.size())
            return w2.size()-i2; // insert that many characters
        if(i2 == w2.size())
            return w1.size()-i1; // delete that many characters
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];

        int minDist = 0;
        if(w1[i1] == w2[i2])
            minDist = _dfs(i1+1, i2+1, w1, w2, dp); // no operations needed
        else
        {
            // 3 options
            //1. Insert the same character as w2[i2] 
            minDist = 1 + _dfs(i1, i2+1, w1, w2, dp);
            //2. Delete a character at i2
            minDist = min(minDist, 1 + _dfs(i1+1, i2, w1, w2, dp));
            //3. Replace a character
            minDist = min(minDist, 1 + _dfs(i1+1, i2+1, w1, w2, dp));
        }
        dp[i1][i2] = minDist;
        return minDist;
    }
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        vector<int> prev(M+1, 0);

        for(auto c = 0; c <= M; ++c)
            prev[c] = c;
            
        vector<int> dp(M+1, 0);
        for(auto r = 1; r <= N; ++r)
        {
            dp[0] = r;    
            for(auto c = 1; c <= M; ++c)
            {
                if(word1[r-1] == word2[c-1])
                {
                    dp[c] = prev[c-1];
                }
                else
                {
                    dp[c] = 1 + min(dp[c-1], min(prev[c], prev[c-1]));
                }
            }
            swap(prev, dp);
        }
        return prev.back();
    }
};
