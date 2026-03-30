class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> tab(text1.size()+1, vector<int>(text2.size() + 1, 0));

        for(auto r = 1; r < tab.size(); ++r)
            for(auto c = 1; c < tab[0].size(); ++c)
            {
                if(text1[r-1] == text2[c-1])
                    tab[r][c] = tab[r-1][c-1] + 1;
                else
                    tab[r][c] = max(tab[r-1][c], tab[r][c-1]);
            }
        return tab.back().back();
    }
};
