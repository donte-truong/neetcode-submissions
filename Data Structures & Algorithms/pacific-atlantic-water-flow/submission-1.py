class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        res = []

        ROWS, COLS = len(heights), len(heights[0])
        visited = set()
        bordersPacific = [[False]*COLS for i in range(ROWS)]

        def dfs(r, c, val):
            nonlocal bordersPacific
            nonlocal res
            if r < 0 or c < 0 or r==ROWS or c==COLS or (r, c) in visited or heights[r][c] < val:
                return

            val = heights[r][c]
            visited.add((r, c))
            if bordersPacific[r][c] == True:
                res.append([r, c])
            bordersPacific[r][c] = True

            dfs(r-1, c, val)
            dfs(r+1, c, val)
            dfs(r, c+1, val)
            dfs(r, c-1, val)
        
        for r in range(ROWS):
            dfs(r, 0, heights[r][0])
        for c in range(1, COLS):
            dfs(0, c, heights[0][c])
        print(bordersPacific)

        visited = set()
        for r in range(ROWS):
            dfs(r, COLS-1, heights[r][COLS-1])
        for c in range(COLS-1):
            dfs(ROWS-1, c, heights[ROWS-1][c])

        return res

        