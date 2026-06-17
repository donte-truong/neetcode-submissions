class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        
        def dfs(s, i):
            if i > n:
                return
            if len(s) == 2*n:
                res.append(s)
                return

            if i == 0:
                dfs(s + "(", i+1)
            elif 2*n - i == len(s):
                dfs(s + ")", i-1)
            else:
                dfs(s + ")", i-1)
                dfs(s + "(", i+1)

        dfs("", 0)

        return res          