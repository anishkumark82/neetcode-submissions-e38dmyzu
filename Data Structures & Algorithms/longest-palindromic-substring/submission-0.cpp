class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int maxL = 0;
        int maxR = 0;
        for(auto i = 0; i < s.size(); ++i)
        {
            // Find all odd palindromes with this element as the center
            int l = i-1;
            int r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
            }
            l++;
            r--;
            if(maxLen < r-l + 1)
            {
                maxLen = r-l + 1;
                maxL = l;
                maxR = r;
            }
            // find all even palindromes with this element as the center
            l = i;
            r = i+1;
            if(s[l] == s[r])
            {
                while(l >= 0 && r < s.size() && s[l] == s[r])
                {
                    l--;
                    r++;
                }
                l++;
                r--;
                if(maxLen < r-l + 1)
                {
                    maxLen = r-l + 1;
                    maxL = l;
                    maxR = r;
                }
            }
        }
        return s.substr(maxL, maxR-maxL + 1);
    }
};
