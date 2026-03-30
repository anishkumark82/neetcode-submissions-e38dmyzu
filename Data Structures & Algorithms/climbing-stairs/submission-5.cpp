class Solution {
public:
    int climbStairs(int n) {
        vector<int>cache(n+1, 0);
        cache[0] = 1;
        cache[1] = 1;
        for(auto i = 2; i < n+1; ++i)
        {
            cache[i] = cache[i-1]+cache[i-2];
        }
        return cache[n];
    }
};
