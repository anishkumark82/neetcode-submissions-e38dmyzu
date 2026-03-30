class Solution {
public:
    int dfs(int n, vector<int>&cache)
    {
        if(cache[n] != -1)
            return cache[n];

        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;

        cache[n] = dfs(n-1, cache) + dfs(n-2, cache);
        return cache[n];
    }
    int climbStairs(int n) {
        vector<int>cache(n+1, -1);
        return dfs(n, cache);        
    }
};
