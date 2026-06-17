class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 1: return 0 if nums[0] == target else -1

        l, r = 0, len(nums)-1
        
        while l < r-1:
            m = l + ((r-l)//2)
            if nums[m] > nums[l]:
                l = m
            elif nums[m] < nums[r]:
                r = m

        indexDiff = len(nums)-r if nums[0] > nums[-1] else 0

        l, r = 0, len(nums)-1

        while l <= r:
            m = l + ((r-l)//2)
            if nums[m-indexDiff] < target:
                l = m+1
            elif nums[m-indexDiff] > target:
                r = m-1
            else:
                return (m-indexDiff) if (m-indexDiff) >= 0 else m + (len(nums)-indexDiff)
        return -1