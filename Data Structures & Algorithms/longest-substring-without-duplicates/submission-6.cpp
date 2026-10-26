class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Input: s = "a b z x y z x y z"
        //                        L         
        //                            R 
        unordered_set<char> chSet;
        int L = 0;
        int maxLen = 0;
        int R = 0;
        for(;R < s.length(); ++R)
        {
            while(chSet.count(s[R]))
            {
                maxLen = max(maxLen, R-L);
                chSet.erase(s[L]);
                L++;
            }
            chSet.insert(s[R]);
        }
        maxLen = max(maxLen, R-L);
        return maxLen;
    }
};
