class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxHeap = []

        for stone in stones:
            heapq.heappush(maxHeap, -stone)
        
        while len(maxHeap) > 1:
            bigStone = -heapq.heappop(maxHeap)
            smallStone = -heapq.heappop(maxHeap)
            bigStone -= smallStone
            heapq.heappush(maxHeap, -bigStone)

        return -maxHeap[0]