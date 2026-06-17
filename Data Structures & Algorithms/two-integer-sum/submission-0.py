class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targetMap = {}
        for i in range(len(nums)):
            targetNum = target-nums[i]
            if str(targetNum) in targetMap:
                return [targetMap[str(targetNum)], i]
            targetMap[str(nums[i])] = i
        return False