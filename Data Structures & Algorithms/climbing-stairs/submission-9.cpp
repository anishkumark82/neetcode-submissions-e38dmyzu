class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1, n2 = 1;
        for(auto i = 2; i < n+1; ++i)
        {
            int tmp = n2;
            n2 += n1;
            n1 = tmp;
        }
        return n2;
    }
};
