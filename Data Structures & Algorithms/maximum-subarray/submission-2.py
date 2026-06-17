class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l = 0
        currSum = 0
        maxSum = nums[0]

        for r in range(len(nums)):
            currSum += nums[r]
            maxSum = max(currSum, maxSum)
            while currSum < 0:
                currSum -= nums[l]
                l += 1

        return maxSum
                