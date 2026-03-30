"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node == None:
            return None

        Q = deque()
        visited = {}
        Q.append(node)
        newNode = Node(node.val)
        visited[node] = newNode

        while Q:
            qSize = len(Q)
            for _ in range(qSize):
                cur = Q.popleft()
                dup = visited[cur]
                for n in cur.neighbors:
                    if n not in visited:
                        nCopy = Node(n.val)
                        visited[n] = nCopy
                        Q.append(n)
                    dup.neighbors.append(visited[n])
        return newNode


