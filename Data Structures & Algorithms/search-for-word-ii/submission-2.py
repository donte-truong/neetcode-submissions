class TrieNode:

    def __init__(self):
        self.children = {}
        self.endOfWord = False

    def addWord(self, word: str):
        curr = self
        for c in word:
            if not c in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endOfWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            root.addWord(word)

        visited = set()
        res = set()

        ROWS, COLS = len(board), len(board[0])
        def dfs(i, j, node, word):
            if node.endOfWord:
                res.add(word)
            if (
                min(i, j) < 0 or i >= ROWS or j >= COLS or
                (i, j) in visited
                or board[i][j] not in node.children
            ):
                return

            visited.add((i, j))
            node = node.children[board[i][j]]
            word += board[i][j]
            dfs(i+1, j, node, word)
            dfs(i-1, j, node, word)
            dfs(i, j+1, node, word)
            dfs(i, j-1, node, word)

            visited.remove((i, j))

        for i in range(ROWS):
            for j in range(COLS):
                dfs(i, j, root, "")

        return list(res)
