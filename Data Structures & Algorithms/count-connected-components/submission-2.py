class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        nodes = {i: set() for i in range(n)}
        visit = [False] * n
        for start, end in edges:
            nodes[start].add(end)
            nodes[end].add(start)

        def dfs(node):
            for adj in nodes[node]:
                if not visit[adj]:
                    visit[adj] = True
                    dfs(adj)

        components = 0
        for i in range(n):
            if not visit[i]:
                dfs(i)
                components += 1
        return components