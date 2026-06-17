class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        right = 0
        left = len(numbers) - 1
        total = numbers[right] + numbers[left]
        while total != target:
            if total < target:
                right += 1
            elif total > target:
                left -= 1
            total = numbers[right] + numbers[left]
        return [right+1, left+1]