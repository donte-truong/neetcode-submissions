class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {0: 0}
        coins.sort()

        for coin in coins:
            dp[coin] = 1

        for i in range(1, amount+1):
            for coin in coins:
                target = i - coin
                if target in dp:
                    dp[i] = min(1 + dp[target], dp.get(i, 2+dp[target]))
        print(dp)
        return dp.get(amount, -1)