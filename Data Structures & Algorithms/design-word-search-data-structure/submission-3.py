class TrieNode:

    def __init__(self):
        self.children = {}
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            if not c in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endOfWord = True

    def search(self, word: str) -> bool:

        def dfs(node, word):
            for i in range(len(word)):
                c = word[i]
                if c == ".":
                    isWord = False
                    for key in node.children:
                        isWord = dfs(node.children[key], "" if i == len(word)-1 else word[i+1:]) or isWord
                    return isWord

                if c not in node.children:
                    return False
                else:
                    node = node.children[c]
            return node.endOfWord

        return dfs(self.root, word)
        
