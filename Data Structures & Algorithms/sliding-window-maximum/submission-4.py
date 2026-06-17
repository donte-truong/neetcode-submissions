class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        window = collections.deque()
        output = []
        l = -1
        for i in range(len(nums)):
            while window and nums[i] >= window[-1][0]:
                window.pop()
            window.append((nums[i], i))
            
            if i >= k-1:
                l += 1
                output.append(window[0][0])
                if window[0][1] == l: window.popleft()
        return output