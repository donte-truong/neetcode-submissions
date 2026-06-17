class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        wl = wr = 0
        waters = [0]*len(height)

        while r >= l:
            wl = max(wl, height[l])
            wr = max(wr, height[r])
            currHeight = min(wl, wr)
            waters[r] = currHeight - height[r]
            waters[l] = currHeight - height[l]

            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1

        return sum(waters)