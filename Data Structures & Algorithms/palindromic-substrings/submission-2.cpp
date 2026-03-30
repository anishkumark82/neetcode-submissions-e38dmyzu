class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for(auto i = 0; i < s.length(); ++i)
        {
            // Odd palindromes
            int L = i;
            int R = i;
            while(L >= 0 && R < s.length() && s[L] == s[R])
            {
                cnt++; // Each is a unique palindrome
                L--;
                R++;
            }

            // Odd palindromes
            L = i;
            R = i+1;
            while(L >= 0 && R < s.length() && s[L] == s[R])
            {
                cnt++; // Each is a unique palindrome
                L--;
                R++;
            }
        }
        return cnt;
    }
};
