class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        for i in range(1, len(s)):
            prev, curr = s[i-1], s[i]
            score += abs(ord(curr) - ord(prev))

        return score
