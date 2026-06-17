class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        prices = [float("infinity")]*n
        prices[src] = 0

        for i in range(k+1):
            temp = prices.copy()
            for s, d, p in flights:
                if prices[s] + p < temp[d]:
                    temp[d] = prices[s] + p
            prices = temp
        
        return prices[dst] if prices[dst] != float("infinity") else -1
