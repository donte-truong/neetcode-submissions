class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        
        visited = set()
        def dfs(r, c):
            if min(r, c) < 0 or r >= ROWS or c >= COLS or (r, c) in visited or grid[r][c] == 0:
                return 0
            
            visited.add((r, c))
            up = dfs(r-1, c)
            down = dfs(r+1, c)
            left = dfs(r, c-1)
            right = dfs(r, c+1)

            return 1 + up + down + left + right

        maxArea = 0
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    maxArea = max(dfs(i, j), maxArea)

        return maxArea