class Solution {
public:
    int climbStairs(int n) {
        int p1 = 1;
        int p2 = 1;
        if(n <= 1)
            return 1;
        p1 = 1;
        p2 = 1;

        for(auto i = 2; i <= n; ++i)
        {
            int t = p1;
            p1 = p2;
            p2 += t;
        }
        return p2;     
    }
};
