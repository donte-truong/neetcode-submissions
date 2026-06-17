class Solution:
    def isHappy(self, n: int) -> bool:
        slow, fast = n, self.sumOfSquares(n)

        while slow != fast:
            fast = self.sumOfSquares(fast)
            fast = self.sumOfSquares(fast)
            slow = self.sumOfSquares(slow)

        return fast == 1
        
    def sumOfSquares(self, n: int):
        output = 0

        while n:
            digit = n % 10
            output += digit ** 2
            n //= 10

        return output