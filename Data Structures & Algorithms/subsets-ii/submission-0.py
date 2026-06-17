class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(i, curr):
            if i == len(nums):
                res.append(curr.copy())
                return

            curr.append(nums[i])
            dfs(i+1, curr)

            val = nums[i]
            while i < len(nums) and val == nums[i]:
                i += 1

            curr.pop()
            dfs(i, curr)

        
        dfs(0, [])
        return res