class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2): return False

        dp = [False]*(len(s1)+1)
        dp[len(s1)] = True

        for i in range(len(s1)-1, -1, -1):
            if s1[i] == s3[i+(len(s3)-len(s1))] and dp[i+1]: 
                dp[i] = True

        for j in range(len(s2)-1, -1, -1):
            print(dp)
            for i in range(len(s1), -1, -1):
                c3 = s3[i+j]
                c1 = s1[i] if i < len(s1) else ""
                c2 = s2[j] if j < len(s2) else ""
                dp[i] = (i < len(s1) and dp[i+1] and c1 == c3) or (dp[i] and c2 == c3)

        return dp[0]