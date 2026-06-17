class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        nodes = {i: [] for i in range(1, n+1)}
        for start, end, time in times:
            nodes[start].append((end, time))

        minHeap = [(0, k)]
        visited = set()
        t = 0

        while minHeap:
            time, node = heapq.heappop(minHeap)
            if node in visited:
                continue

            visited.add(node)
            t = max(time, t)

            for adj, weight in nodes[node]:
                if adj not in visited:
                    heapq.heappush(minHeap, (time+weight, adj))

        return t if len(visited) == n else -1
