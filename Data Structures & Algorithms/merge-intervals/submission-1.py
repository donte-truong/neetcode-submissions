class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        prevInterval = intervals[0]

        res = []
        for i in range(1, len(intervals)):
            currInterval = intervals[i]
            if prevInterval[1] >= currInterval[0]:
                prevInterval = [
                    prevInterval[0],
                    max(prevInterval[1], currInterval[1])
                ]
            else:
                res.append(prevInterval)
                prevInterval = currInterval

        res.append(prevInterval)
        return res
        