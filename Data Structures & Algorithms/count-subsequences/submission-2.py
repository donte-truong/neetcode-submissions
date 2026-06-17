class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        dp = [1]*(len(s)+1)

        for j in range(len(t)-1, -1, -1):
            prev = 0
            print(dp)
            for i in range(len(s)-1, -1, -1):
                temp = dp[i]
                if s[i] == t[j]:
                    dp[i] = dp[i+1] + prev
                else:
                    dp[i] = dp[i+1] if i < len(s)-1 else 0
                prev = temp
            dp[len(s)] = 0

        print(dp)
        return dp[0]