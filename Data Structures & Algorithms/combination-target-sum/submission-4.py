class Solution:
    def __init__(self):
        self.out = []
        self.cur = []
    def _dfs(self, nums: List[int], idx: int, target: int):
        if target == 0:
            self.out.append(self.cur[:])
            return
        
        if target < 0 or idx == len(nums):
            return
        
        self.cur.append(nums[idx])
        #Take all cases where current value is included
        self._dfs(nums, idx, target-nums[idx])
        self.cur.pop()
        # Take case not including current value
        self._dfs(nums, idx+1, target)

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        self._dfs(nums, 0, target)
        return self.out        