class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

        int l = 0;
        int r = 0;
        int maxLen = 0;
        // p w w k e w
        //     ||
        //     lr
        // maxLen = 2
        // charSet -- 
        while(r < s.size())
        {
            while(charSet.find(s[r]) != charSet.end())
            {
                maxLen = max(maxLen, r-l);
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            r++;
        }
        maxLen = max(maxLen, r-l);
        return maxLen;   
    }
};
