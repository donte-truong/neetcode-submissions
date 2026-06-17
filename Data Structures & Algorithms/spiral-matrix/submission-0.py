class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ROWS, COLS = len(matrix), len(matrix[0])
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        di = 0
        res = []
        row, col = 0, 0
        for i in range(ROWS*COLS):
            res.append(matrix[row][col])
            matrix[row][col] = None

            row += directions[di][0]
            col += directions[di][1]
            if min(row, col) < 0 or row >= ROWS or col >= COLS or matrix[row][col] is None:
                row -= directions[di][0]
                col -= directions[di][1]
                di = (di+1)%4
                row += directions[di][0]
                col += directions[di][1]

        return res