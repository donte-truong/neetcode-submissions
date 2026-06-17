class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])

        minHeap = [[grid[0][0], 0, 0]]
        visited = set()
        directions = [(1,0),(-1,0),(0,1),(0,-1)]

        while minHeap:
            cost, r, c = heapq.heappop(minHeap)
            if r == ROWS - 1 and c == COLS - 1:
                return cost

            for dr, dc in directions:
                newR, newC = r+dr, c+dc
                if min(newR, newC) < 0 or newR >= ROWS or newC >= COLS or (newR, newC) in visited:
                    continue
                visited.add((r, c))
                heapq.heappush(minHeap, [max(cost, grid[newR][newC]), newR, newC])
