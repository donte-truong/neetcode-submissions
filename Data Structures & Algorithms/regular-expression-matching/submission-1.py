class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        dp = {}

        def dfs(i, j, matcher):
            if i == len(s) and j == len(p):
                return True
            if (i, j) in dp:
                return dp[(i, j)]
            if j == len(p) or i > len(s):
                return False

            c = s[i] if i < len(s) else ""
            r = p[j]
            if j < len(p)-1 and p[j+1] == '*':
                dp[(i, j)] = dfs(i, j+1, r)
            elif r == '*':
                moveOn = dfs(i+1, j+1, matcher) and matcher in c+"."
                nextC = dfs(i+1, j, matcher) and matcher in c+"."
                noUse = dfs(i, j+1, matcher)
                dp[(i, j)] = moveOn or nextC or noUse
            elif r == ".":
                dp[(i, j)] = dfs(i+1, j+1, matcher)
            elif c == r:
                dp[(i, j)] = dfs(i+1, j+1, matcher)
            else:
                dp[(i, j)] = False

            return dp[(i, j)]

        return dfs(0, 0, p[0])