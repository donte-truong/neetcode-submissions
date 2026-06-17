class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        edges = {}
        nodes = {}
        for src, dest in tickets:
            if not src in nodes:
                nodes[src] = []
            nodes[src].append(dest)
            edges[(src, dest)] = 1 + edges.get((src, dest), 0)

        def dfs(node, path):
            path.append(node)
            if len(edges) == 0:
                return path

            nodes.get(node, []).sort()
            for adj in nodes.get(node, []):
                if (node, adj) in edges:
                    edges[(node, adj)] -= 1
                    if edges[(node, adj)] == 0:
                        del edges[(node, adj)]
                    path = dfs(adj, path)
                    if len(edges) == 0:
                        return path
                    edges[(node, adj)] = 1 + edges.get((node, adj), 0)
            path.pop()
            return path

        return dfs('JFK', [])