class Graph:
    
    def __init__(self):
        self.adjList = {}

    def _dfs(self, src: int, dst: int, visited: set) -> bool:
        if src == dst:
            return True
        
        if src in visited:
            return False

        nb = self.adjList[src]
        for c in nb:
            if self._dfs(c, dst, visited):
                return True
        return False

    def addEdge(self, src: int, dst: int) -> None:
        if src not in self.adjList:
            self.adjList[src] = set()
        if dst not in self.adjList:
            self.adjList[dst] = set()
        
        self.adjList[src].add(dst)

    def removeEdge(self, src: int, dst: int) -> bool:
        if src not in self.adjList:
            return False
        if dst not in self.adjList[src]:
            return False
        self.adjList[src].remove(dst)
        return True

    def hasPath(self, src: int, dst: int) -> bool:
        if src not in self.adjList or dst not in self.adjList:
            return False
        visited = set()
        return self._dfs(src, dst, visited)
