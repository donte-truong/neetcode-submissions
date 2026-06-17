class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = {}

        def dfs(i, j):
            if i == len(word1) and j == len(word2):
                return 0
            if i > len(word1) or j > len(word2):
                return float("infinity")
            if (i, j) in dp:
                return dp[(i, j)]

            c1 = word1[i] if i < len(word1) else ""
            c2 = word2[j] if j < len(word2) else ""

            if c1 == c2:
                dp[(i, j)] = dfs(i+1, j+1)
            else:
                dp[(i, j)] = min(1+dfs(i+1, j), 1+dfs(i, j+1), 1+dfs(i+1, j+1))

            return dp[(i, j)]

        return dfs(0, 0)