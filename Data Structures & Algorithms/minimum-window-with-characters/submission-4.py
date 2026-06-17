class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s): 
            return ""
        sCounter, tCounter = {}, {}
        matches = 52
        for i in range(len(t)):
            sCounter[s[i]] = 1 + sCounter.get(s[i], 0)
            tCounter[t[i]] = 1 + tCounter.get(t[i], 0)
        for key in tCounter:
            if tCounter[key] > sCounter.get(key, 0):
                matches -= 1

        if matches == 52: return s[:len(t)]
        start, end = float("-infinity"), float("infinity")
        l = 0
        for r in range(len(t), len(s)):
            sCounter[s[r]] = 1 + sCounter.get(s[r], 0)
            if tCounter.get(s[r], 0) == sCounter.get(s[r], 0):
                matches += 1

            while matches == 52:
                sCounter[s[l]] -= 1
                if sCounter[s[l]] < tCounter.get(s[l], 0):
                    matches -= 1
                    start, end = (l, r+1) if (r-l+1) < (end-start) else (start, end)
                l += 1
        return s[start:end] if start != float("-infinity") else ""