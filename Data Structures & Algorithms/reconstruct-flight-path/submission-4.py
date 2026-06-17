class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        edges = {}
        nodes = {}
        for source, dest in tickets:
            if not source in nodes:
                nodes[source] = []
            nodes[source].append(dest)
            edges[(source, dest)] = 1+edges.get((source, dest), 0)
        
        def dfs(node, path):
            if len(edges) == 0:
                path.append(node)
                return path

            path.append(node)
            nodes.get(node, []).sort()
            for adj in nodes.get(node, []):
                if (node, adj) in edges:
                    edges[(node, adj)] -= 1
                    if edges[(node, adj)] == 0: del edges[(node, adj)]
                    newPath = dfs(adj, path)
                    if len(edges) == 0:
                        return newPath
                    edges[(node, adj)] = 1 + edges.get((node, adj), 0)
            path.pop()
            return path

        return dfs('JFK', [])