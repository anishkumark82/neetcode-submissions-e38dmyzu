class Solution:
    def _insertQ(self, grid: List[List[int]], 
                Q: Deque[tuple[int]], r: int, c: int, 
                rMax: int, cMax: int,  
                visited: set) -> None :

        rInBounds = r >= 0 and r < rMax
        cInBounds = c >= 0 and c < cMax

        if not rInBounds or not cInBounds:
            return
        
        if grid[r][c] != 0 or (r, c) in visited:
            return
        
        visited.add((r, c))
        Q.append((r, c))

    def shortestPath(self, grid: List[List[int]]) -> int:
        visited = set()
        Q = deque()
        
        # important constant variables
        rMax = len(grid)
        cMax = len(grid[0])
        iLOC = [(-1, 0), (1, 0), (0, -1), (0, 1)] # All neigbors in 4 direction

        Q.append((0, 0))
        visited.add((0, 0))

        slen = -1
        while Q:
            slen += 1
            qSize = len(Q)
            for _ in range(qSize):
                r, c = Q.popleft()

                if r == rMax-1 and c == cMax-1:
                    return slen
                for i in range(len(iLOC)):
                    self._insertQ(grid, Q, r+iLOC[i][0], c+iLOC[i][1], rMax, cMax, visited)
            
        return -1
                


