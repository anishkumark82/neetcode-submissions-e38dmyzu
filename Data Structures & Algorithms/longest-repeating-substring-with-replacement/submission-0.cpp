class Solution {
private:
    int _findMostFreq(vector<int>charCnt)
    {
        int maxVal = 0;
        for(auto &ch : charCnt)
            maxVal = max(maxVal, ch);
        return maxVal;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int>charCnt(26, 0);
        int maxLen = 0;
        int l = 0;
        int r = 0;
        charCnt[s[r]-'A']++;
        while(r < s.size())
        {
            int maxRep = _findMostFreq(charCnt);
            if((r-l + 1) - maxRep > k)
            {
                maxLen = max(maxLen, r-l);
                charCnt[s[l]-'A']--;
                l++;
            }
            else
            {
                r++;
                if(r < s.size())
                    charCnt[s[r]-'A']++;
            }
        }
        maxLen = max(maxLen, r-l);
        return maxLen;
    }
};
