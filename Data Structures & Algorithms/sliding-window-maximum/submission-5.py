class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        window = collections.deque()
        output = []
        l = -1
        for i in range(len(nums)):
            while window and nums[i] >= nums[window[-1]]:
                window.pop()
            window.append(i)
            
            if i >= k-1:
                l += 1
                output.append(nums[window[0]])
                if window[0] == l: window.popleft()
        return output