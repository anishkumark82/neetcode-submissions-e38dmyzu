class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        curCnt = 0
        maxCnt = 0
        for n in nums:
            curCnt = curCnt+1 if n else 0
            maxCnt = max(curCnt, maxCnt)
        return maxCnt
        