class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size())
            return 0;

        int N = s.size();
        int M = t.size();
        vector<int> prev(M+1, 0);
        vector<int> dp(M+1, 0);
        prev[0] = 1;
        dp[0] = 1;

        for(auto r = 1; r <= N; ++r)
        {            
            for(auto c = 1; c <=M; ++c)
            {
                dp[c] = prev[c];
                if(s[r-1] == t[c-1])
                    dp[c] += prev[c-1];
            }
            swap(prev, dp);
        }
        return prev.back();
    }
};
