class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights)-1
        maxWater = 0
        while r > l:
            currWater = min(heights[r], heights[l])*(r-l)
            if heights[r] <= heights[l]:
                r -= 1
            else:
                l += 1
            maxWater = max(maxWater, currWater)
        return maxWater