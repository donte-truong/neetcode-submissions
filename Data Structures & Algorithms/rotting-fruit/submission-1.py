class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        bananas = set()
        visited = set()
        q = deque()

        def addCell(r, c):
            if r < 0 or c < 0 or r == ROWS or c == COLS or (r, c) in visited or grid[r][c] == 0:
                return
            visited.add((r, c))
            q.append([r, c])
            bananas.remove((r, c))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    visited.add((r, c))
                    q.append([r, c])
                    grid[r][c] = 0
                if grid[r][c] == 1:
                    bananas.add((r, c))

        if len(bananas) == 0:
            return 0

        dist = 0
        while q:
            for i in range(len(q)):
                r, c = q.popleft()
                grid[r][c] == 0
                addCell(r-1, c)
                addCell(r+1, c)
                addCell(r, c-1)
                addCell(r, c+1)
            dist += 1

        if len(bananas) == 0:
            return dist-1
        
        return -1
