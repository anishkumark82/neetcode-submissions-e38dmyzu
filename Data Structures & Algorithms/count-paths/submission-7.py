class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0] * n
        newDp = [0] * n
        
        for r in range(m-1, -1, -1):
            newDp[n-1] = 1
            for c in range(n-2, -1, -1):
                newDp[c] = dp[c] + newDp[c+1]
            dp = newDp
    
        return dp[0]



