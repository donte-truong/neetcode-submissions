class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums:
            subsets = []
            for prev in res:
                subsets.append(prev + [num])
            res.extend(subsets)
        return res