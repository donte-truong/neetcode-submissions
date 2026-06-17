class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        
        waterHeight = height.copy()
        area = 0
        l, r = 0, 1
        currMax = height[l]

        while r < len(height):
            if height[r] >= currMax:
                currMax = height[r]
                prevMax = height[l]
                l += 1
                while l < r:
                    water = max(prevMax-height[l], 0)
                    waterHeight[l] += water
                    area += water
                    l += 1
            r += 1
        r -= 1
        l = r-1
        currMax = height[r]
        while l >= 0:
            if height[l] >= currMax:
                print(l, r)
                currMax = height[l]
                prevMax = height[r]
                r -= 1
                while r > l:
                    water = max(prevMax-waterHeight[r], 0)
                    waterHeight[r] += water
                    area += water
                    r -= 1
            l -= 1
        print(waterHeight)
        return area

