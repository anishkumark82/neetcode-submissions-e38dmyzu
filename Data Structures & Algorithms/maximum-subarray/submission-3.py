class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curSum = 0
        maxSum = nums[0]
        for n in nums:
            curSum = n if curSum < 0 else curSum + n
            maxSum = max(maxSum, curSum)
        return maxSum