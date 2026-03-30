class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chSet;
        int maxLen = 0;
        int L = 0;
        int R = 0;
        int curLen = 1;    
        for(; R < s.length(); ++R)
        {
            while(chSet.find(s[R]) != chSet.end() && R >= L)
            {
                chSet.erase(s[L]);
                L++;
            }
            chSet.insert(s[R]);
            maxLen = max(maxLen, R-L+1);
        } 
        return maxLen;   
    }
};
