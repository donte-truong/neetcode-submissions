class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1)+len(s2) != len(s3): return False

        dp = {}

        def dfs(i, j):
            if i == len(s1) and j == len(s2):
                return True
            if (i, j) in dp: return dp[(i, j)]
            
            c1 = s1[i] if i < len(s1) else ""
            c2 = s2[j] if j < len(s2) else ""
            c3 = s3[i+j]

            if c1 == c2 and c1 == c3:
                dp[(i, j)] = dfs(i+1, j) or dfs(i, j+1)
            elif c1 == c3:
                dp[(i, j)] = dfs(i+1, j)
            elif c2 == c3:
                dp[(i, j)] = dfs(i, j+1)
            else:
                dp[(i, j)] = False

            return dp[(i, j)]

        return dfs(0, 0)