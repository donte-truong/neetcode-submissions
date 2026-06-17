class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()

        for interval in intervals:
            interval.append(interval[1]-interval[0]+1)

        res = []
        for q in queries:
            dist = -1
            for interval in intervals:
                if interval[0] <= q and interval[1] >= q:
                    dist = min(dist, interval[2]) if dist != -1 else interval[2]
            res.append(dist)

        return res
            
