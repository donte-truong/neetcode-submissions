class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        def quickSelect(nums, k):
            p = 0
            for i in range(len(nums)-1):
                if nums[i] <= nums[-1]:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            nums[p], nums[-1] = nums[-1], nums[p]
            print(nums, p)

            kth = len(nums) - k
            if kth == p:
                return nums[p]
            
            if kth > p:
                return quickSelect(nums[p+1:], k) 
            if kth < p:
                return quickSelect(nums[:p], k - (len(nums) - p))

        return quickSelect(nums, k)

            