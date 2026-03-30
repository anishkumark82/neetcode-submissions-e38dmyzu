class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(auto i = 0; i < s.size(); ++i)
        {
            // find all odd palindromes with i as center
            count++; // the character itself
            int l = i-1;
            int r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
            // find all even palindromes with i and i+1 as center
            l = i;
            r = i+1;
            if(r < s.size() && s[l] == s[r])
            {
                while(l >= 0 && r < s.size() && s[l] == s[r])
                {
                    count++;
                    l--;
                    r++;
                }
            }
        }
        return count;
    }
};
