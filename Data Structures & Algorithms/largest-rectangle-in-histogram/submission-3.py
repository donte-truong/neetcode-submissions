class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        maxArea = 0
        stack = []

        for i in range(n+1):
            while stack and (i==n or heights[stack[-1]] >= heights[i]):
                currHeight = heights[stack.pop()]
                width = i if not stack else i-stack[-1] - 1
                maxArea = max(maxArea, currHeight*width)
            stack.append(i)

        return maxArea
