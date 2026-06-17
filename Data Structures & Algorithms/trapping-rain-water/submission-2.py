class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        wl = wr = 0
        res = 0

        while r >= l:
            wl = max(wl, height[l])
            wr = max(wr, height[r])
            currHeight = min(wl, wr)

            if height[l] <= height[r]:
                res += currHeight - height[l]
                l += 1
            else:
                res += currHeight - height[r]
                r -= 1

        return res