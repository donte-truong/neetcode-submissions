class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        p = 0
        for i in range(len(nums)-1):
            if nums[i] <= nums[-1]:
                nums[i], nums[p] = nums[p], nums[i]
                p += 1
        nums[p], nums[-1] = nums[-1], nums[p]

        kth = len(nums) - k
        if kth == p:
            return nums[p]
        
        if kth > p:
            return self.findKthLargest(nums[p+1:], k)
        if kth < p:
            return self.findKthLargest(nums[:p], k - (len(nums) - p))

            