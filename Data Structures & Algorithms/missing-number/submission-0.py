class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        bit = 0
        for num in nums:
            bit += 1 << num

        res = 0
        while bit & 1 == 1:
            res += 1
            bit >>= 1
        return res