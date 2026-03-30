class Solution:
    def topologicalSort(self, n: int, edges: List[List[int]]) -> List[int]:
        # assertion: Topological sort expects a directed graph

        # Adj dictionary
        adj = {}
        for i in range(n):
            adj[i] = []
        for e in edges:
            adj[e[0]].append(e[1])

        # visited set to track nodes already visited via DFS
        visited = set()
        # path set to track for nodes to see if there are cycles in the current path
        path = set()
        
        sorted = []

        def dfs(i: int) -> bool:        
            if i in path:
                return False
            if i in visited:
                return True
            
            visited.add(i)
            path.add(i)

            for n in adj[i]:
                if dfs(n) == False:
                    return False

            sorted.append(i)
            path.remove(i)
            return True

        # Run DFS and store the sorted dynamic array
        for i in range(n):
            if not dfs(i):
                return []

        sorted.reverse()

        # Reverse the array
        return sorted
