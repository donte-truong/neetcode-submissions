class Solution:
    def isPalindrome(self, s:str) -> bool:
        n = len(s)
        mid = n//2 - 1

        increment = 1 if n%2 == 0 else 2
        for i in range(mid+1):
            if s[mid-i] != s[mid+i+increment]:
                return False
        
        return True

    def partition(self, s: str) -> List[List[str]]:
        res = []

        def dfs(i, currS, ans):
            print(currS, ans)
            if i == len(s):
                if currS == "":
                    res.append(ans.copy())
                return

            currS += s[i]
            
            dfs(i+1, currS, ans)

            if self.isPalindrome(currS):
                ans.append(currS)
                dfs(i+1, "", ans)
                ans.pop()

        dfs(0, "", [])
        return res

