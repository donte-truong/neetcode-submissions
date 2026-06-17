class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        numsSet = set()

        for num in nums:
            if num in numsSet: return num
            else: numsSet.add(num)