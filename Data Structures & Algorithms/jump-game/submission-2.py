class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums)-1

        for i in range(len(nums)-2, -1, -1):
            jump = nums[i]
            if i + jump >= goal:
                goal = i

        return goal == 0
        