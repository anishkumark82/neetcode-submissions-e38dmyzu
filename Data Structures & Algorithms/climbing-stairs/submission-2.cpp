class Solution {
public:
    int climbStairs(int n) {
        // Classic DP problem
        // Bottom up DP
        int n0 = 1;
        int n1 = 1;

        for(auto i = 2; i <= n; ++i)
        {
            int t = n1;
            n1 += n0;
            n0 = t;
        }
        return n1;
    }
};
