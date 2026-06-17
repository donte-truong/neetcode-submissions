class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l, r = 0, len(matrix)-1
        row = -1
        while l <= r:
            m = l + ((r-l)//2)
            if matrix[m][0] > target:
                r = m - 1
            elif matrix[m][-1] < target:
                l = m + 1
            else:
                row = m
                break
        
        l, r = 0, len(matrix[row])-1
        column = -1
        while l <= r:
            m = l + ((r-l)//2)
            if matrix[row][m] > target:
                r = m - 1
            elif matrix[row][m] < target:
                l = m + 1
            else:
                column = m
                break

        return False if row == -1 or column == -1 else True