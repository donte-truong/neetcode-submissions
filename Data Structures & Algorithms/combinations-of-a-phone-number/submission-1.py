class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        charMap = [[],[],
            ["a", "b", "c"],
            ["d", "e", "f"],
            ["g", "h", "i"],
            ["j", "k", "l"],
            ["m", "n", "o"],
            ["p", "q", "r", "s"],
            ["t", "u", "v"],
            ["w", "x", "y", "z"]
        ]

        if digits == "": return []

        def dfs(i, curr):
            if i == len(digits):
                res.append(curr)
                return

            digit = int(digits[i])
            n = len(charMap[digit])
            for j in range(n):
                dfs(i+1, curr+charMap[digit][j])

        dfs(0, "")
        return res