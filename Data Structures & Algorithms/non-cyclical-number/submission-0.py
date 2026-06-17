class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()

        while n not in seen:
            seen.add(n)
            newN = 0
            while n > 0:
                digit = n % 10
                newN += digit**2
                n //= 10
            n = newN

        return n == 1