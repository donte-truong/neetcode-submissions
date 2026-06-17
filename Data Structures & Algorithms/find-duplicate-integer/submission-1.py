class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            currNum = nums[i]
            for j in range(i+1, len(nums)):
                if nums[j] == currNum: return currNum