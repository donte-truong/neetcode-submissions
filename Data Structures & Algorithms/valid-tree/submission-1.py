class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        nodes = {i: set() for i in range(n)}
        for start, end in edges:
            nodes[start].add(end)
            nodes[end].add(start)

        visited = set()
        cycle = set()
        def dfs(n):
            if n in cycle:
                return False
            
            visited.add(n)
            if len(nodes[n]) == 0:
                return True

            cycle.add(n)
            for node in nodes[n]:
                nodes[node].remove(n)
                print(nodes, node)
                if not dfs(node):
                    return False
            cycle.remove(n)
            nodes[n] = set()
            return True

        return dfs(0) and len(visited) == n