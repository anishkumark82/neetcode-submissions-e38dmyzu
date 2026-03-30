class Solution:
    def _dfs(self, grid: List[List[str]], 
            r: int, c: int, 
            rMax: int, cMax: int, 
            visited: List[List[bool]]) -> bool:

        # check if index valid
        rInBounds = r >= 0 and r < rMax
        cInBounds = c >= 0 and c < cMax
        if not rInBounds or not cInBounds:
            return False

        # Already visited or water
        if grid[r][c] != '1' or visited[r][c] == True:
            return False

        visited[r][c] = True
        
        # explore 4 degrees of freedom
        self._dfs(grid, r-1, c, rMax, cMax, visited)
        self._dfs(grid, r+1, c, rMax, cMax, visited)
        self._dfs(grid, r, c-1, rMax, cMax, visited)
        self._dfs(grid, r, c+1, rMax, cMax, visited)

        return True

    def numIslands(self, grid: List[List[str]]) -> int:
        rMax = len(grid)
        cMax = len(grid[0])
        visited = [[False for _ in range(cMax)] for _ in range(rMax)]
        count = 0

        for r in range(0, rMax):
            for c in range(0, cMax):
                count = count + 1 if self._dfs(grid, r, c, rMax, cMax, visited) else count
        return count