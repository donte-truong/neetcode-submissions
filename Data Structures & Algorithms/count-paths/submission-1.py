class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        x = (m-1)+(n-1)
        y = m-1

        numerator = 1
        denominator = 1
        for i in range(y):
            numerator *= x-i
            denominator *= y-i
        return int(numerator/denominator)