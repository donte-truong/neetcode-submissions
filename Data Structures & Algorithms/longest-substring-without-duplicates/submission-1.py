class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        back = 0
        maxLength = 0
        for front in range(len(s)):
            if s[front] in mp:
                back = max(mp[s[front]]+1, back)
            mp[s[front]] = front
            maxLength = max(maxLength, front-back+1)
        return maxLength