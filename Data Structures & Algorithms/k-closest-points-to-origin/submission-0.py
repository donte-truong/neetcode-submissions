class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        pointMap = {}

        for point in points:
            distance = math.sqrt((point[0]**2) + (point[1]**2))
            currList = pointMap.get(distance, [])
            currList.append(point)
            pointMap[distance] = currList
            heapq.heappush(heap, -distance)

        while len(heap) > k:
            heapq.heappop(heap)

        res = []
        for distance in heap:
            res.append(pointMap[-distance].pop())
        return res