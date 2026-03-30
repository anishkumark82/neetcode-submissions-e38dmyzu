class Graph:
    
    def __init__(self):
        self.adjList = {}

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
        # BFS algorithm
        
        # Validity check
        if src not in self.adjList or dst not in self.adjList:
            return False
        
        Q = deque()
        visited = set()

        Q.append(src)
        visited.add(src)

        while Q:
            qSize = len(Q)
            for _ in range(qSize):
                cur = Q.popleft()
                
                if cur == dst:
                    return True
                
                nb = self.adjList[cur]
                for e in nb:
                    if e not in visited:
                        Q.append(e)

        return False


