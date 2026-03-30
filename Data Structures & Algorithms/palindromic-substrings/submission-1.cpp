class Solution {
public:
    int countSubstrings(string s) {
        // abcacbbc
        // "a" "b", "bcacb", "c", "cac", "ac" (n^3)

        // "a", "b", "c", "a", "cac", "bcacb", b, b, c, cbbc 
        // "abc"
        int count = 0;
        for(auto i = 0; i < s.size(); ++i)
        {
            // Find all odd Palindromes with i as center element
            count++;
            int l = i-1;
            int r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
                count++;
            }
            // find all even palindromes
            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
                count++;
            }
        }
        return count;
    }
};
