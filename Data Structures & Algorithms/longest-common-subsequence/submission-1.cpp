class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> tab(text1.size()+1, vector<int>(text2.size() + 1, 0));
        if(text1.size() < text2.size())
            longestCommonSubsequence(text2, text1);
            
        vector<int> prev(text2.size() + 1, 0);
        vector<int> cur(text2.size() + 1, 0);
        for(auto r = 1; r <= text1.size(); ++r)
        {
            for(auto c = 1; c <= text2.size(); ++c)
            {
                if(text1[r-1] == text2[c-1])
                    cur[c] = prev[c-1] + 1;
                else
                    cur[c] = max(prev[c], cur[c-1]);
            }
            prev = cur;
        }    
        return prev.back();
    }
};
