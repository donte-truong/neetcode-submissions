class Solution:
    def climbStairs(self, n: int) -> int:
        prev = 1
        curr = 1
        i = 1

        while i < n:
            temp = curr
            curr = prev + curr
            prev = temp

            i += 1

        return curr