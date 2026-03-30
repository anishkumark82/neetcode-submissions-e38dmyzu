"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def _dfs(self, node, visited):
        if node == None:
            return None
        
        if node in visited:
            return visited[node]

        nCopy = Node(node.val)
        visited[node] = nCopy

        for n in node.neighbors:
            nCopy.neighbors.append(self._dfs(n, visited))

        return nCopy

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        visited = {}
        return self._dfs(node, visited)

