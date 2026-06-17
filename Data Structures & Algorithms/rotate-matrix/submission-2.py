class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        ROWS, COLS = len(matrix), len(matrix[0])

        for row in range(ROWS):
            for col in range(COLS):
                newRow, newCol = col, -row + (COLS-1)
                print(newRow, newCol)
                if type(matrix[row][col]) is tuple:
                    matrix[newRow][newCol] = (matrix[newRow][newCol], matrix[row][col][0])
                    matrix[row][col] = matrix[row][col][1]
                else:
                    matrix[newRow][newCol] = (matrix[newRow][newCol], matrix[row][col])

        for row in range(ROWS):
            for col in range(COLS):
                if type(matrix[row][col]) is tuple:
                    matrix[row][col] = matrix[row][col][1]
        
