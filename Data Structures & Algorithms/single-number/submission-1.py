class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        smallest = min(nums)
        bit = 0
        for num in nums:
            bit = bit ^ (1 << (num-smallest))
        
        i = 0
        while bit != 1:
            bit = bit >> 1
            i += 1
        return i+smallest