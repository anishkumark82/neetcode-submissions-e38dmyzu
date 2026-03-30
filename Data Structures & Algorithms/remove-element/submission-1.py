class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for ele in nums :
            if ele != val :
                nums[i] = ele
                i += 1
        return i