class Solution:
    def _insertQ(self, grid: List[List[int]], Q: Deque[tuple(int)], r: int, c: int, rMax: int, cMax: int) -> None:
        rInBounds = r >= 0 and r < rMax
        cInBounds = c >= 0 and c < cMax

        if not rInBounds or not cInBounds:
            return
        
        if grid[r][c] != 1:
            return

        grid[r][c] = 2
        Q.append((r,c))

    def orangesRotting(self, grid: List[List[int]]) -> int:
        rMax = len(grid)
        cMax = len(grid[0])
        Q = deque()

        nfruits = 0
        nfinal = 0
        time = -1

        N = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:
                    nfruits += 1
                elif grid[r][c] == 2:
                    nfruits += 1
                    Q.append((r, c))

        if nfruits == 0:
            return 0

        while Q:
            time += 1
            qSize = len(Q)
            nfinal += qSize
            for _ in range(qSize):
                cord = Q.popleft()
                r = cord[0]
                c = cord[1]
                for i in range(len(N)):
                    self._insertQ(grid, Q, r+N[i][0], c+N[i][1], rMax, cMax)
        
        return time if nfinal == nfruits else -1
