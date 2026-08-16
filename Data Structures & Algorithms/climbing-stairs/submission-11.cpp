class Solution {
// dfs : 2^n
// Memoization : 2^n, Time (O(n)), Space O(n)

private: 
    int _dfs(int n, vector<int> &memo)
    {
        if (n == 0)
            return 1;
        if(n < 0)
            return 0;
        
        if(memo[n] != -1)
            return memo[n];

        // 1 step
        memo[n] = _dfs(n-1, memo) + _dfs(n-2, memo);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return _dfs(n, memo);
    }
};
