class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        ROWS, COLS = len(matrix), len(matrix[0])
        subs = [[0]*COLS for _ in range(ROWS)]

        ans = 1
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        def dfs(i, j):
            nonlocal ans
            if subs[i][j] != 0: return subs[i][j]

            val = matrix[i][j]
            longestPath = 1
            for dr, dc in directions:
                r, c, = i+dr, j+dc
                if min(r, c) < 0 or r >= ROWS or c >= COLS or matrix[r][c] >= val:
                    continue
                longestPath = max(1+dfs(r, c), longestPath)
            subs[i][j] = longestPath
            ans = max(longestPath, ans)
            return longestPath
        
        for i in range(ROWS):
            for j in range(COLS):
                dfs(i, j)

        return ans
                    