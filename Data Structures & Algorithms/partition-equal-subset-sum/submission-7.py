class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1: return False

        target = total // 2
        dp = set()
        dp.add(0)

        for num in nums:
            nextDp = set()
            for t in dp:
                if t + num == target:
                    return True
                nextDp.add(t + num)
                nextDp.add(t)
            dp = nextDp

        return target in dp