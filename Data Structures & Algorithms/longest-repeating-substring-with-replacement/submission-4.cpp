class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>chCount = vector<int>(26, 0);
        // 0 1 2 3 4 5 6 7 8 9
        // B A A B C B B C A B
        // L
        //   R
        // maxLen = 1 
        // chCount B = 1, A = 1
        // maxE - 1
        // size 2
        // size - maxE = 1
        int L = 0;
        int R = 0;
        int maxLen = 0;
        while(R < s.length())
        {
            int size = R - L + 1;
            chCount[s[R]-'A']++;
            int maxE = *max_element(chCount.begin(), chCount.end());
            while(size - maxE > k && L <= R)
            {
                maxLen = max(maxLen, R-L);
                chCount[s[L]-'A']--;
                L++;
                size = R - L + 1;
                maxE = *max_element(chCount.begin(), chCount.end());
            }
            R++;
        }
        maxLen = max(maxLen, R-L);
        return maxLen;
    }
};
