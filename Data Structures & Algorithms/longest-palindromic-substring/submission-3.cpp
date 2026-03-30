class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int maxL = -1;
        int maxR = -1;
        string out;

        for(auto i = 0; i < s.size(); ++i)
        {
             // All odd pallindromes with i as center
            int L = i;
            int R = i;
            while(L >= 0 && R < s.length() && s[L] == s[R])
            {
                L--;
                R++;
            }
            if(maxLen < R-L-1)
            {
                maxLen = R-L-1;
                maxL = L+1;
            }

            // All even pallindromes with i and i+1 as center
            L = i;
            R = i+1;
            while(L >= 0 && R < s.length() && s[L] == s[R])
            {
                L--;
                R++;
            }
            if(maxLen < R-L-1)
            {
                maxLen = R-L-1;
                maxL = L+1;
            }
        }
        out = {s.begin()+maxL, s.begin()+maxL + maxLen};
        return out;
    }
};
