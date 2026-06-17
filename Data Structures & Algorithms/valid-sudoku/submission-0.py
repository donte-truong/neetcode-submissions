class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        rows = [{} for i in range(n)]
        columns = [{} for j in range(n)]
        squares = [{} for k in range(n)]

        for i in range(len(board)):
            for j in range(len(board[i])):
                value = board[i][j]
                if value == ".":
                    continue

                if rows[i].get(value) or columns[j].get(value) or squares[3*(i//3) + (j//3)].get(value):
                    return False

                rows[i][value] = 1
                columns[j][value] = 1
                squares[(i//3) + (j//3)][value] = 1

        return True