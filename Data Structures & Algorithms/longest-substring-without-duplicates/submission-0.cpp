class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        while(r < s.size())
        {
            if(charSet.find(s[r]) != charSet.end())
            {
                maxLen = max(maxLen, r-l);
                auto itr = charSet.find(s[l]);
                charSet.erase(itr);
                l++;
            }
            else
            {
                charSet.insert(s[r]);
                r++;
            }
        }
        maxLen = max(maxLen, r-l);
        return maxLen;
    }
};
