class Solution {
public:
    string longestPalindrome(string s) {
        string maxStr = "";
        int maxLen = 0;

        for(auto i = 0; i < s.length(); ++i)
        {
            // Odd palindrome
            int L = i;
            int R = i;
            while(L >= 0 && R < s.size() && s[L] == s[R])
            {
                L--;
                R++;
            }
            if(maxLen < R - L - 1)
            {
                maxLen = R - L - 1;
                maxStr = {s.begin()+ (L+1), s.begin()+ R};
            }

            // Even palindrome
            L = i;
            R = i+1;
            while(L >= 0 && R < s.size() && s[L] == s[R])
            {
                L--;
                R++;
            }
            if(maxLen < R - L - 1)
            {
                maxLen = R - L - 1;
                maxStr = {s.begin()+L+1, s.begin() + R};
            }

        }
        return maxStr;
    }
};
