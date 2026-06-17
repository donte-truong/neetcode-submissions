class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        mp = {}
        for i, c in enumerate(s):
            if not c in mp:
                mp[c] = []
            mp[c] = i

        res = []
        i = 0
        while i < len(s):
            end = mp[s[i]]+1
            j = i+1
            while j < end:
                c = s[j]
                if mp[c]+1 > end:
                    end = mp[c]+1
                j += 1
            res.append(end-i)
            i = end
        return res