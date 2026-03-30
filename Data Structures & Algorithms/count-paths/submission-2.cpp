class Solution {
public:
    
    // Via Tabulation or bottom up
    // Time Complexity O(mn)
    // Space Complexity O(mn)
    int uniquePaths(int m, int n) {
        vector<vector<int>> tab(m, vector<int>(n, -1));
        for(auto c = 0; c < n; ++c)
            tab[m-1][c] = 1;

        for(int r = m-2; r >= 0; --r)
            for(int c = n-1; c >= 0; --c)
            {
                tab[r][c] = tab[r+1][c];
                tab[r][c] += ((c < n-1) ? tab[r][c+1] : 0);
            }
        return tab[0][0];
    }
};
