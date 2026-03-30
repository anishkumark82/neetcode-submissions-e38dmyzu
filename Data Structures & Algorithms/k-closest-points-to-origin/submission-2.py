class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        maxHeap = [] # maintain a max heap of size k
        out = []

        for i in range (0, len(points)):
            dist = -1 * (points[i][0] ** 2 + points[i][1] ** 2)
            heapq.heappush(maxHeap, [dist, i])
            if len(maxHeap) > k:
                heapq.heappop(maxHeap)
            
        while len(maxHeap) != 0:
            i = heapq.heappop(maxHeap)[1]
            out.append(points[i])
        
        return out


        