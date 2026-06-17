class Solution:
    def isEdge(self, s1, s2):
        if len(s1) != len(s2): return False

        diff = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                diff += 1
        return diff == 1

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList.append(beginWord)
        nodes = {word: [] for word in wordList}
        for i in range(len(wordList)-1):
            for j in range(i+1, len(wordList)):
                if self.isEdge(wordList[i], wordList[j]):
                    nodes[wordList[i]].append(wordList[j])
                    nodes[wordList[j]].append(wordList[i])

        visited = set()
        def dfs(word):
            if word == endWord:
                return 1
            
            visited.add(word)
            dist = 0
            for adj in nodes[word]:
                if adj not in visited:
                    val = dfs(adj)
                    if val != 0 and (dist == 0 or val + 1 < dist):
                        dist = val + 1
            visited.remove(word)
            return dist

        return dfs(beginWord)