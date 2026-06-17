class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        minCost = float("infinity")

        prev, curr = cost[0], cost[1]

        for i in range(2, len(cost)):
            temp = curr
            curr = min(prev, curr) + cost[i]
            prev = temp

        return min(prev, curr)