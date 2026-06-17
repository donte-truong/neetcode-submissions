class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        nodes = {i: set() for i in range(1, len(edges)+1)}
        for start, end in edges:
            nodes[start].add(end)
            nodes[end].add(start)

        startCycle, stop = 0, False
        visit, cycle = set(), set()
        def dfs(node):
            nonlocal startCycle, stop
            if node in visit:
                startCycle = node
                return True
            if len(nodes[node]) == 0:
                return False

            visit.add(node)
            for adj in nodes[node]:
                nodes[adj].remove(node)
                if dfs(adj):
                    if not stop or startCycle != adj: cycle.add((node, adj))
                    if startCycle != 0: stop = True
                    return True
            visit.remove(node)
            return False
        
        dfs(1)
        print(cycle)

        i = -1
        for j, edge in enumerate(edges):
            if (
                ((edge[0], edge[1]) in cycle or ((edge[1], edge[0]) in cycle)) and 
                j > i
            ):
                i = j
        return edges[i]
        