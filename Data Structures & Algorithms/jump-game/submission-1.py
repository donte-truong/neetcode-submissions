class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [False]*len(nums)
        dp[len(nums)-1] = True

        for i in range(len(nums)-2, -1, -1):
            jump = nums[i]
            for j in range(min(jump+1, len(nums)-i)):
                if dp[i+j] is True:
                    dp[i] = True
        return dp[0]
        