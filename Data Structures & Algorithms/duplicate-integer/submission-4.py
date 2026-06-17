class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mp = set()

        for num in nums:
            if num in mp:
                return True
            mp.add(num)

        return False