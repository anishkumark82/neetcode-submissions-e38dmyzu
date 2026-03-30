class Solution:
    def _dfs(self, grid: List[List[int]], r: int, c: int, rMax: int, cMax: int) -> int :

        # check validity
        rInBounds = r >= 0 and r < rMax
        cInBounds = c >= 0 and c < cMax

        if not rInBounds or not cInBounds:
            return 0
        
        if grid[r][c] != 1:
            return 0
        
        grid[r][c] = -1 # Assuming we can change the original matrix

        area = 1
        area += self._dfs(grid, r-1, c, rMax, cMax)
        area += self._dfs(grid, r+1, c, rMax, cMax)
        area += self._dfs(grid, r, c-1, rMax, cMax)
        area += self._dfs(grid, r, c+1, rMax, cMax)
        return area

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rMax = len(grid)
        cMax = len(grid[0])

        maxArea = 0
        for r in range(rMax):
            for c in range(cMax):
                maxArea = max(maxArea, self._dfs(grid, r, c, rMax, cMax))
        return maxArea