class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        def dfs(row, col):
            if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]):
                return 0
            if grid[row][col] == 0:
                return 0

            grid[row][col] = 0
            total = dfs(row-1, col) + dfs(row+1, col) + dfs(row, col-1) + dfs(row, col+1)
            return 1+total

        maxArea = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                maxArea = max(maxArea, dfs(i, j))
        return maxArea