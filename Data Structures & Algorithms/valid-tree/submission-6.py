class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        nodes = {i: set() for i in range(n)}
        for u, v in edges:
            nodes[u].add(v)
            nodes[v].add(u)

        visited = set()
        cycle = set()
        def dfs(node):
            if node in cycle:
                return False

            visited.add(node)
            cycle.add(node)
            for adj in nodes[node]:
                nodes[adj].remove(node)
                if not dfs(adj):
                    return False
            cycle.remove(node)
            nodes[node] = set()
            return True

        return dfs(0) and len(visited) == n