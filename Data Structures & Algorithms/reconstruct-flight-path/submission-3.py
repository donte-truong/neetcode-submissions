class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        edges = {}
        nodes = {}
        reverse = {}
        for source, dest in tickets:
            if not source in nodes:
                nodes[source] = []
                reverse[source] = []
            if not dest in reverse:
                reverse[dest] = []
                nodes[dest] = []
            nodes[source].append(dest)
            reverse[dest].append(source)
            edges[(source, dest)] = 1+edges.get((source, dest), 0)

        print(nodes)

        endNode = 'JFK'
        for node in nodes:
            if len(reverse[node]) > len(nodes[node]):
                endNode = node
        
        def dfs(node, path):
            if node == endNode and len(edges) == 0:
                path.append(node)
                return path

            path.append(node)
            nodes[node].sort()
            for adj in nodes[node]:
                if (node, adj) in edges:
                    edges[(node, adj)] -= 1
                    if edges[(node, adj)] == 0: del edges[(node, adj)]
                    newPath = dfs(adj, path)
                    if newPath[-1] == endNode and len(edges) == 0:
                        return newPath
                    edges[(node, adj)] = 1 + edges.get((node, adj), 0)
            path.pop()
            return path

        return dfs('JFK', [])