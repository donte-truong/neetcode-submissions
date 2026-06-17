class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [-1]*len(nums)
        dp[len(nums)-1] = 0

        for i in range(len(nums)-2, -1, -1):
            jump = nums[i]
            minDist = -1
            for j in range(i+1, min(len(nums), i+jump+1)):
                dist = dp[j]
                if (dist < minDist and dist != -1) or minDist == -1:
                    minDist = dist
            dp[i] = minDist+1 if minDist != -1 else -1
            print(dp)
        return dp[0]