class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l <= r:
            m = l + ((r-l)//2)
            if nums[m] == target:
                return m
            elif m == l:
                break
            elif nums[m] < target:
                l = m
            elif nums[m] > target:
                r = m
        return -1 if nums[r] != target else r