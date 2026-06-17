def charMap(s: str) -> List[int]:
        chars = [0]*26
        for char in s:
            chars[ord(char)-ord('a')] += 1
        return chars

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counter = 0
        anagramMaps = {}
        outputList = []
        for s in strs:
            stringMap = charMap(s)
            if str(stringMap) not in anagramMaps:
                anagramMaps[str(stringMap)] = counter
                outputList.append([s])
                counter += 1
            else:
                print(anagramMaps, outputList)
                outputList[anagramMaps[str(stringMap)]].append(s)
        return outputList