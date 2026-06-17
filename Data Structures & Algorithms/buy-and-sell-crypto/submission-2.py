class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = r = 0
        maxProfit = 0
        for i in range(len(prices)):
            r = i
            profit = prices[r] - prices[l]
            if profit < 0:
                l = r
            maxProfit = max(maxProfit, profit)

        return maxProfit