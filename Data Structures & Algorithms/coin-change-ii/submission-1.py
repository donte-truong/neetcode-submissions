class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        curr = [0]*(amount+1)
        curr[0] = 1

        for coin in coins:
            for a in range(1, amount+1):
                curr[a] += curr[a-coin] if a-coin >= 0 else 0

        return curr[amount]