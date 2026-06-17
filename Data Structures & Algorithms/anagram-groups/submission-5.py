class Solution:
    def charMap(self, s: str):
        chars = [0]*26
        for c in s:
            i = ord(c) - ord('a')
            chars[i] += 1
        return chars

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramMaps = {}
        outputList = []
        count = 0
        for s in strs:
            charMap = self.charMap(s)
            if str(charMap) not in anagramMaps:
                anagramMaps[str(charMap)] = count
                outputList.append([s])
                count += 1
            else:
                index = anagramMaps[str(charMap)]
                outputList[index].append(s)
        return outputList
