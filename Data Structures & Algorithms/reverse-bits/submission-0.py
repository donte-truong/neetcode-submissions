class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        i = 31
        while n != 0:
            res += (n&1) << i
            n >>= 1
            i -= 1
        return res