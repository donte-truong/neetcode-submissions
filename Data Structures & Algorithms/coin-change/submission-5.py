class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {0:0}

        for i in range(1, amount+1):
            for coin in coins:
                target = i - coin
                if target in dp:
                    dp[i] = min(dp[target] + 1, dp.get(i, float("infinity")))

        return dp.get(amount, -1)