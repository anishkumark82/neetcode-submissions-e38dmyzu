class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        nSet = set()

        for n in nums:
            if n in nSet:
                return True
            nSet.add(n)
        return False