class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Create an adj List
        adj = {}
        for i in range(numCourses):
            adj[i] = []
        for p in prerequisites:
            adj[p[0]].append(p[1])

        visited = set() # A set to track visited vertices
        path = set() # track cycles
        sorted = [] # final output

        def dfs(i:int) -> bool:
            if i in path:
                return False
            
            if i in visited:
                return True
            
            visited.add(i)
            path.add(i)

            for n in adj[i]:
                if not dfs(n):
                    return False
            
            path.remove(i)
            sorted.append(i)
            return True

        for i in range(numCourses):
            if not dfs(i):
                return []
        
        return sorted

