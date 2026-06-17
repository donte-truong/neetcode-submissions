class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def dfs(i, row, col):
            nonlocal stack

            if i == len(word):
                return True
            if row < 0 or row >= len(board) or col < 0 or col >= len(board[row]):
                return False
            if board[row][col] != word[i]:
                return False

            if board[row][col] == word[i]:
                for pos in stack:
                    if pos[0] == row and pos[1] == col:
                        return False
                print(row, col, word[i])
                stack.append((row, col))
                i += 1
            
            up = dfs(i, row-1, col)
            down = dfs(i, row+1, col)
            left = dfs(i, row, col-1)
            right = dfs(i, row, col+1)

            ans = (up or down or left or right)
            if not ans:
                stack.pop()

            return ans
        
        res = False
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == word[0]:
                    stack = []
                    res = dfs(0,i,j) or res
        return res
            