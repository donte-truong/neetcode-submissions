class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = [0] * 26

        matches = 26
        for c in s:
            idx = ord(c) - ord('a')
            mp[idx] += 1
            if mp[idx] == 1: matches -= 1

        for c in t:
            idx = ord(c) - ord('a')
            mp[idx] -= 1
            if mp[idx] == 0: matches += 1
            if mp[idx] == -1: matches -= 1

        return matches == 26
