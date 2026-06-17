class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        nodes = {i: [] for i in range(1, n+1)}
        for start, end, time in times:
            nodes[start].append((time, end))

        spt = {i: float("infinity") for i in range(1, n+1)}
        spt[k] = 0
        q = deque()
        q.append(k)
        while q:
            node = q.popleft()
            neighbors = nodes[node]
            heapq.heapify(neighbors)
            print(neighbors)
            while neighbors:
                time, adj = heapq.heappop(neighbors)
                spt[adj] = min(spt[adj], spt[node]+time)
                q.append(adj)
            nodes[node] = []

        maxTime = -1
        for node in spt:
            maxTime = max(maxTime, spt[node])
        return -1 if maxTime == float("infinity") else maxTime