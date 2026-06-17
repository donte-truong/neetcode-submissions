class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        end = len(s)
        for i in range(len(s)-1, -1, -1):
            c = s[i]
            if c.isalpha() and end == len(s): end = i
            if c.isspace() and end < len(s): 
                return end - i

        return end+1