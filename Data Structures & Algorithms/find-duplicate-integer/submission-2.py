class     Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # modifying the original array
        for i in range(len(nums)):
            idx = abs(nums[i])
            if nums[idx] < 0:
                return abs(idx)
            nums[idx] = -1 * nums[idx]
            
        return -1