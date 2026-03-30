class Solution:
    def _dfs(self, n: int, adjList: List[List[int]], visited: List[bool]) -> bool:
        if visited[n] == True:
            return False
        
        visited[n] = True
        for nb in adjList[n]:
            if self._dfs(nb, adjList, visited) == False:
                return False

        visited[n] = False
        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = {i:[] for i in range(numCourses)}
        visited = {i: False for i in range(numCourses)}

        for p in prerequisites:
            adjList[p[0]].append(p[1])
        
        for i in range(numCourses):
            if self._dfs(i, adjList, visited) == False:
                return False
        return True