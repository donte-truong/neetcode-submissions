class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        counter = {}
        for num in nums:
            if not num in counter:
                counter[num] = 1
            else:
                return True
        return False
        