class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        
        lis = [1]*len(nums)

        for i in range(len(nums)):
            sub = [lis[j] for j in range(i) if nums[j] < nums[i]]
            sub.append(0)
            lis[i] = 1 + max(sub)

        return max(lis)