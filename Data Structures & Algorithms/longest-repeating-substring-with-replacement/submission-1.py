class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counter = {}
        l = 0
        maxf = 1
        maxLength = 0
        for r in range(len(s)):
            counter[s[r]] = 1 + counter.get(s[r], 0)
            maxf = max(maxf, counter[s[r]])
            while (r-l+1) > k + maxf:
                counter[s[l]] -= 1
                l += 1
            maxLength = max(maxLength, r-l+1)
        return maxLength
