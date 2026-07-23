class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        int p0 = 1;
        int p1 = 1;
        for(auto i = 2; i <=n; ++i)
        {
            int tmp = p1;
            p1 = p1 + p0;
            p0 = tmp;
        }
        return p1;
    }
};
