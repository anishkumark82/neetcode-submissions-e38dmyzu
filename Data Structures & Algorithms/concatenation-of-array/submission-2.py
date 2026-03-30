class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ret = list(nums)
        for ele in nums :
            ret.append(ele)
        return ret