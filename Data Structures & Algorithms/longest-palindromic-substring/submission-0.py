class Solution:
    def checkPalindrome(self, start: float, s: str):
        left, right = start, start
        if (start*10) % 10 == 5:
            left -= 0.5
            right += 0.5
        while left >= 0 and right < len(s) and s[int(left)] == s[int(right)]:
            left -= 1
            right += 1
        return (int(left+1), int(right))

    def longestPalindrome(self, s: str) -> str:
        maxS = (0,0)

        i = 0
        while i < len(s):
            currMax = self.checkPalindrome(i, s)
            if currMax[1] - currMax[0] >= maxS[1] - maxS[0]:
                maxS = currMax
            i += 0.5
        
        return s[maxS[0]:maxS[1]]