def charMap(s: str) -> List[int]:
        chars = [0]*26
        for char in s:
            chars[ord(char)-ord('a')] += 1
        return chars

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramMaps = {}
        for s in strs:
            stringMap = charMap(s)
            if str(stringMap) not in anagramMaps:
                anagramMaps[str(stringMap)] = [s]
            else:
                anagramMaps[str(stringMap)].append(s)
        return list(anagramMaps.values())