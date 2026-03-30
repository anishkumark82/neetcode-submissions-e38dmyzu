class Solution {
public:
    
    // Via Tabulation or bottom up
    // Time Complexity O(mn)
    // Space Complexity O(n)
    int uniquePaths(int m, int n) {
        vector<int>prev(n, 1);
        vector<int>cur(n, 0);
        
        for(int r = m-2; r >= 0; --r)
        {
            for(int c = n-1; c >= 0; --c)
            {
                cur[c] = prev[c];
                cur[c] += ((c < n-1) ? cur[c+1] : 0);
            }
            prev = cur;
        }
        return prev[0];
    }
};
