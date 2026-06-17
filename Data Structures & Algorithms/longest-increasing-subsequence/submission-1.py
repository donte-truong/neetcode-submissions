class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        
        lis = [1]*len(nums)

        for i in range(len(nums)):
            subs = [lis[j] for j in range(i) if nums[i] > nums[j]]
            subs.append(0)
            lis[i] = 1 + max(subs)

        return max(lis)