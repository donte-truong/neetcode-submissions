class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        if len(points) == 1: return 0
        nodes = set()
        edges = []
        for i in range(len(points)):
            nodes.add(i)
            for j in range(i+1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                edges.append((abs(x2-x1) + abs(y2-y1), i, j))

        res = 0
        components = {node: node for node in nodes}
        edges.sort()
        for dist, u, v in edges:
            if components[u] != components[v]:
                res += dist
                old_comp, new_comp = components[u], components[v]
                for x in components:
                    if components[x] == old_comp:
                        components[x] = new_comp
        return res