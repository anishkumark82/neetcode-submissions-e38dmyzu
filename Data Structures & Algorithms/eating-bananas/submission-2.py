import math

class Solution:
    def _isCocoFinishPile(self, piles: List[int], k: int, h: int):
        totalHrs = 0
        for p in piles:
            totalHrs += math.ceil(p/k)
            if totalHrs > h:
                return False
        return True

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # assuming the piles.size() <= h
        low = 1
        high = max(piles)
        res = -1
        while low <= high:
            mid = low + (high-low) // 2

            if self._isCocoFinishPile(piles, mid, h):
                res = mid
                high = mid-1
            else:
                low = mid+1
        return res