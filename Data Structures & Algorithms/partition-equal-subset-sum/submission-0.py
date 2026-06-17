class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1: return False

        target = total // 2
        dp = {0:set()}

        for i in range(1, target+1):
            for j, num in enumerate(nums):
                val = i - num
                if val in dp:
                    prev = dp[val].copy()
                    if j not in prev:
                        prev.add(j)
                        dp[i] = prev
            print(dp)

        return True if dp.get(target, False) else False