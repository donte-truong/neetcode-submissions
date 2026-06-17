class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(i, ans):
            if i == len(nums):
                res.append(ans.copy())
                return

            ans.append(nums[i])
            dfs(i+1, ans)

            ans.pop()
            dfs(i+1, ans)

        dfs(0, [])
        return res
