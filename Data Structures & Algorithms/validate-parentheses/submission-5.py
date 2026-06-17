class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) < 2:
            return False
        cMap = {")":"(", "}":"{", "]":"["}
        stack = []
        for char in s:
            if char not in cMap:
                stack.append(char)
            elif not stack or cMap.get(char) != stack[-1]:
                return False
            else:
                stack.pop()
        return False if stack else True