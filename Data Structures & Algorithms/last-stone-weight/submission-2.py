class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        minHeap = []
        for i in range(0, len(stones)):
            minHeap.append(-1 * stones[i])

        heapq.heapify(minHeap)

        while len(minHeap) > 1:
            t1 = heapq.heappop(minHeap)
            t2 = heapq.heappop(minHeap)
            diff = t1-t2
            if diff != 0:
                heapq.heappush(minHeap, diff)
        return abs(minHeap[0]) if len(minHeap) != 0 else 0
