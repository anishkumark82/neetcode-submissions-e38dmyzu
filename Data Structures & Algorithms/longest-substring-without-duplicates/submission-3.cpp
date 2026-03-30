class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chSet;

        int l = 0;
        int maxLen = 0;
        for(auto r = 0; r < s.length(); ++r)
        {
            while(chSet.find(s[r]) != chSet.end() && l <= r)
            {
                chSet.erase(s[l]);
                l++;
            }
            chSet.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
