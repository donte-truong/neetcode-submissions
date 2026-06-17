class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1: return 0
        maxProfit = 0
        front, back = 1, 0

        while front < len(prices):
            currProfit = prices[front]-prices[back]
            if currProfit >= 0:
                front += 1
            else:
                back += 1
            maxProfit = max(currProfit, maxProfit)

        return maxProfit