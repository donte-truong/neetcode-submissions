class Solution:
    def isEdge(self, s1, s2):
        if len(s1) != len(s2):
            return False
        
        different = 0
        for i in range(len(s1)):
            c1 = s1[i]
            c2 = s2[i]
            if c1 != c2:
                different += 1
        return different == 1

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList.append(beginWord)
        nodes = {s: set() for s in wordList}

        for i in range(len(wordList)-1):
            for j in range(i+1, len(wordList)):
                if self.isEdge(wordList[i], wordList[j]):
                    word1, word2 = wordList[i], wordList[j]
                    nodes[word1].add(word2)
                    nodes[word2].add(word1)

        visited = set()
        def dfs(word):
            if word == endWord:
                return 1

            dist = 0
            visited.add(word)
            for adj in nodes[word]:
                if adj not in visited:
                    val = dfs(adj)
                    if val != 0 and (val+1 < dist or dist == 0):
                        dist = val + 1
            visited.remove(word)
            return dist

        return dfs(beginWord)