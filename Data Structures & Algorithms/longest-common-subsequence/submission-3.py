class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if len(text1) < len(text2):
            text1, text2 = text2, text1

        prev = [0]*(len(text1)+1)
        curr = [0]*(len(text1)+1)

        for i in range(len(text2)-1, -1, -1):
            for j in range(len(text1)-1, -1, -1):
                c1, c2 = text1[j], text2[i]
                if c1 == c2:
                    curr[j] = 1 + prev[j+1]
                else:
                    curr[j] = max(curr[j+1], prev[j])
            prev, curr = curr, prev

        return prev[0]