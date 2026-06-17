class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        currMin = currMax = 1
        maxProd = nums[0]

        for num in nums:
            tempMax = currMax * num
            tempMin = currMin * num
            currMax = max(tempMax, tempMin, num)
            currMin = min(tempMax, tempMin, num)
            maxProd = max(currMax, maxProd)

        return maxProd


