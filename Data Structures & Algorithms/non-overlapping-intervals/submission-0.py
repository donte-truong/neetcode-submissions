class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        res = 0
        prev = intervals[0]

        for i in range(1, len(intervals)):
            curr = intervals[i]

            if curr[0] < prev[1]:
                if curr[1] < prev[1]:
                    prev = curr
                res += 1
            else:
                prev = curr

        return res
        