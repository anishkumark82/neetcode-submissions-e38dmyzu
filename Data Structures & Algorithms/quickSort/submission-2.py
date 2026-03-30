# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def _qSHelper(self, pairs: List[Pair], s: int, e: int) -> None:
        if e <= s:
            return
        p = self._qSPartion(pairs, s, e)
        self._qSHelper(pairs, s, p-1)
        self._qSHelper(pairs, p+1, e)
        
    def _qSPartion(self, pairs: List[Pair], s: int, e: int) -> int:
        pivot = pairs[e].key # taking last element as the pivot
        cur = s
        slot = s
        while cur < e:
            if pairs[cur].key < pivot:
                pairs[slot], pairs[cur] = pairs[cur], pairs[slot]
                slot += 1
            cur += 1
        pairs[e], pairs[slot] = pairs[slot], pairs[e]
        return slot

    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        self._qSHelper(pairs, 0, len(pairs)-1)
        return pairs
