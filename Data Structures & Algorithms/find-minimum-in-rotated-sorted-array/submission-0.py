class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]:
            return nums[0]

        l, r = 0, len(nums)-1

        while l < r-1:
            m = l + ((r-l)//2)
            if nums[m] > nums[l]:
                l = m
            elif nums[m] < nums[r]:
                r = m
        
        return nums[r]
