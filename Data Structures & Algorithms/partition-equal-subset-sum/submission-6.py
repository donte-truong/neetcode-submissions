class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1: return False

        target = total // 2
        dp = set()
        dp.add(0)

        for i in range(len(nums)):
            nextDp = set()
            for t in dp:
                if t + nums[i] == target:
                    return True
                nextDp.add(t+nums[i])
                nextDp.add(t)
                print(nextDp)
            dp = nextDp

        return target in dp