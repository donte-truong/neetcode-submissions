class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        minCost = float("infinity")

        prev, curr = cost[0], cost[1]

        for i in range(2, len(cost)):
            temp = min(prev, curr) + cost[i]
            prev = curr
            curr = temp

        return min(prev, curr)