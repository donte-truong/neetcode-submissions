class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        maxArea = 0
        while l < r:
            currArea = min(heights[l],heights[r])*(r-l)
            maxArea = max(currArea, maxArea)
            if heights[l] < heights[r]:
                l += 1
            elif heights[l] > heights[r]:
                r -= 1
            elif heights[l] == heights[r]:
                l += 1
                r -= 1
        return maxArea