# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def _mergeSort(self, pairs:List[Pair], s:int, e:int) -> None :
        if e <= s : # Reached the lowest level
            return

        m = (s + e) // 2
        self._mergeSort(pairs, s, m)
        self._mergeSort(pairs, m+1, e)
        self._merge(pairs, s, m, e)
    
    def _merge(self, pairs: List[Pair], s: int, m: int, e: int) -> void :
        L = pairs[s:m+1]
        R = pairs[m+1:e+1]
        i = 0
        j = 0
        k = s
        while i < len(L) and j < len(R):
            if L[i].key <= R[j].key: 
                pairs[k] = L[i]
                k += 1
                i += 1
            else:
                pairs[k] = R[j]
                k += 1
                j += 1
        while i < len(L):
            pairs[k] = L[i]
            k += 1
            i += 1
        while j < len(R):
            pairs[k] = R[j]
            k += 1
            j += 1
        
        
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        self._mergeSort(pairs, 0, len(pairs)-1)
        return pairs
        
