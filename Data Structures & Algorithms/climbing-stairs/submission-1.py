class Solution:
    def climbStairs(self, n: int) -> int:
        prev = 1
        curr = 1
        i = n-1
        while i > 0:
            temp = curr + prev
            prev = curr
            curr = temp
            i -= 1
        return curr