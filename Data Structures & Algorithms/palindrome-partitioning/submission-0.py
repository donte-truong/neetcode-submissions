class Solution:
    def isPalindrome(self, s:str) -> bool:
        n = len(s)
        mid = n//2 - 1

        for i in range(mid+1):
            if n % 2 == 0 and s[mid-i] != s[mid+i+1]:
                return False
            elif n % 2 == 1 and s[mid-i] != s[mid+2+i]:
                return False
        
        return True

    def partition(self, s: str) -> List[List[str]]:
        res = []

        def dfs(i, currS, ans):
            if i == len(s):
                print(currS, ans)
                if currS == "":
                    res.append(ans.copy())
                return

            currS = currS + s[i]

            dfs(i+1, currS, ans)

            if self.isPalindrome(currS):
                ans.append(currS)
                dfs(i+1, "", ans)
                ans.pop()

        dfs(0, "", [])
        return res

