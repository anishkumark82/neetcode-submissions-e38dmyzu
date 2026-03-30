class Solution:
    def __init__(self):
        self.out = []
        self.cur = []
    def _dfs(self, nums: List[int], idx : int) -> None :
        if idx == len(nums):
            self.out.append(self.cur[:])
            return
        
        # include current element
        self.cur.append(nums[idx])
        self._dfs(nums, idx+1)
        self.cur.pop()
        # subset that does not include the current element
        self._dfs(nums, idx+1)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self._dfs(nums, 0)
        return self.out