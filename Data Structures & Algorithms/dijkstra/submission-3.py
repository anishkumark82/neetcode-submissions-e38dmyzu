class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], src: int) -> Dict[int, int]:
        adj = {}
        for i in range(n):
            adj[i] = []
            
        for e in edges:
            adj[e[0]].append([e[1], e[2]])
        
        shortest = {}
        minHeap = [[0, src]]

        while minHeap:
            w1, u = heapq.heappop(minHeap)

            if u in shortest:
                continue
            shortest[u] = w1

            nbrs = adj[u]
            for v, w2 in nbrs:
                if v not in shortest:
                    heapq.heappush(minHeap, [w2+w1, v])
            
        for i in range(n):
            if i not in shortest:
                shortest[i] = -1

        return shortest

