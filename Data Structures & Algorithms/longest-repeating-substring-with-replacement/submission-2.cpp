class Solution {
public:
    bool isWithin_K_Replacements(vector<int> &chMap, int k)
    {
        int maxVal = *max_element(chMap.begin(), chMap.end());
        int total = accumulate(chMap.begin(), chMap.end(), 0);
        return total-maxVal <= k; 
    }
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int L = 0;
        vector<int> chMap(26, 0);
        
        for(auto R = 0; R < s.length(); ++R)
        {
            chMap[s[R]-'A']++;
            while(!isWithin_K_Replacements(chMap, k) && L <= R)
            {
                // Start moving L pointer
                chMap[s[L]-'A']--;
                L++;
            }
            maxLen = max(maxLen, R-L+1);
        }

        return maxLen;
    }
};
