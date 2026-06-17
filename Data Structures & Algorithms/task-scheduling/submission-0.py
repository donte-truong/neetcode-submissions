class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        heap = []
        for key in count.keys():
            heap.append(-count[key])
        heapq.heapify(heap)

        time = 0
        q = deque()

        while q or heap:

            time += 1

            if not heap:
                time = q[0][1]
            else:
                count = -heapq.heappop(heap) - 1
                if count > 0:
                    q.append([count, time+n])

            if q and q[0][1] == time:
                heapq.heappush(heap, -q.popleft()[0])

        return time