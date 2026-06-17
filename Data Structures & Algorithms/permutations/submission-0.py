class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(curr, candidates):
            if len(curr) == len(nums):
                res.append(curr.copy())
                return

            for i in range(len(candidates)):
                curr.append(candidates[i])
                newCandidates = candidates[:i] + candidates[i+1:]
                dfs(curr, newCandidates)
                curr.pop()

        dfs([], nums)
        return res