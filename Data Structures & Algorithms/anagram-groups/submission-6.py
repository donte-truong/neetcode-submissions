class Solution:
    def charMap(self, s: str):
        chars = [0]*26
        for c in s:
            i = ord(c) - ord('a')
            chars[i] += 1
        return chars

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramMaps = {}
        res = []

        for s in strs:
            mp = self.charMap(s)
            if str(mp) in anagramMaps:
                anagramMaps[str(mp)].append(s)
            else:
                anagramMaps[str(mp)] = [s]

        for m in anagramMaps:
            res.append(anagramMaps[m])

        return res
