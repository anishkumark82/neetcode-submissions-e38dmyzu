class Solution {
public:
    int countSubstrings(string s) {
        // Find all odd and even palindromes at each location
        int cnt = 0;
        for(auto i = 0; i < s.size(); ++i)
        {
            // all odd palindromes with this element as center
            int L = i;
            int R = i;
            while(L >= 0 && R < s.size() && s[L] == s[R])
            {
                L--;
                R++;
                cnt++;
            }
            // all even palindromes with this element as center
            L = i;
            R = i+1;
            while(L >= 0 && R < s.size() && s[L] == s[R])
            {
                L--;
                R++;
                cnt++;
            }
        }
        return cnt;
    }
};
