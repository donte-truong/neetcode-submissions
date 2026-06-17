class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hashSet = set()

        for num in nums:
            hashSet.add(num)

        res = 0
        for i in range(len(nums)):
            num = nums[i]
            if not num-1 in hashSet:
                length = 0
                while num in hashSet:
                    length += 1
                    num += 1
                res = max(length, res)

        return res
        