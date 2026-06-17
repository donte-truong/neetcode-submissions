class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        maxLen = 0
        for num in nums:
            if (num - 1) not in numSet:
                currLength = 1
                while (num + currLength) in numSet:
                    currLength += 1
                maxLen = max(maxLen, currLength)
        return maxLen