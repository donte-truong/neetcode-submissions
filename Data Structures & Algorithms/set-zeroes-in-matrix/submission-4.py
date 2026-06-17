class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        zeroCol = False
        zeroRow = False
        
        for row in range(len(matrix)):
            for col in range(len(matrix[row])):
                if matrix[row][col] == 0:
                    if row == 0: zeroRow = True
                    if col == 0: zeroCol = True
                    matrix[0][col] = 0
                    matrix[row][0] = 0

        for row in range(1, len(matrix)):
            if matrix[row][0] == 0:
                for col in range(len(matrix[row])):
                    matrix[row][col] = 0
        for col in range(1, len(matrix[0])):
            if matrix[0][col] == 0:
                for row in range(len(matrix)):
                    matrix[row][col] = 0

        if zeroCol:
            for row in range(len(matrix)):
                matrix[row][0] = 0
        if zeroRow:
            for col in range(len(matrix[0])):
                matrix[0][col] = 0