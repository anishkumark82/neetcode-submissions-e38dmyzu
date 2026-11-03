class Solution {
public:
    int characterReplacement(string s, int k) {
        int total = 0;
        int curMax = 0;
        int maxLen = 0;
        int L = 0;
        int R = 0;
        //s=" A A A B A B B", k = 2;
        //    L
        //          R
        //chCount - A = 3, B = 1
        // total = 1 - 0 + 1 = 3
        // curMax = 3
        // maxLen = 3
        vector<int> chCount(26, 0);
        while(R < s.length())
        {
            chCount[s[R]-'A']++;
            total = R-L+1;
            curMax = *max_element(chCount.begin(), chCount.end());
            // move left pointer if more than k replacements is needed
            while(L < R && total - curMax > k )
            {
                chCount[s[L] - 'A']--;
                L++;
                curMax = *max_element(chCount.begin(), chCount.end());
                total = R-L+1;
            }
            maxLen = max(maxLen, total);
            R++;
        }
        return maxLen;
    }
};
