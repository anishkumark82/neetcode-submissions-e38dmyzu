class Solution {
    int findAllPalindromes(int L, int R, string &s)
    {
        int cnt = 0;
        while(L >= 0 && R < s.size() && s[L] == s[R])
        {
            L--;
            R++;
            cnt++;
        }
        return cnt;
    }

public:
    int countSubstrings(string s) {
        // Find all odd and even palindromes at each location
        int cnt = 0;
        for(auto i = 0; i < s.size(); ++i)
        {
            // all odd palindromes with this element as center
            cnt += findAllPalindromes(i, i, s);
            // all even palindromes with this element as center
            cnt += findAllPalindromes(i, i+1, s);
        }
        return cnt;
    }
};
