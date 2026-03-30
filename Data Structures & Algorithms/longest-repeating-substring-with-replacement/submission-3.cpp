class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>chMap(26, 0);
        
        int L = 0;
        int R = 0;
        int maxLen = 0;
        while(R < s.size())
        {
            chMap[s[R] - 'A']++;
            int numRep = (R-L + 1) - (*max_element(chMap.begin(), chMap.end()));
            if(numRep > k)
            {
                chMap[s[L]-'A']--;
                L++;
            }
            maxLen = max(maxLen, R-L+1);
            R++;

        }
        return maxLen;
    }
};
