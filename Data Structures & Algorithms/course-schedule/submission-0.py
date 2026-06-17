class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        def dfs(edges, node, visited, recStack):
            if recStack[node]:
                return True

            if visited[node]:
                return False

            visited[node] = True
            recStack[node] = True

            for adj in edges[node]:
                if dfs(edges, adj, visited, recStack):
                    return True

            recStack[node] = False
            return False

        def constructEdges(nodes, edgesList):
            edges = [[] for _ in range(nodes)]
            for u, v in edgesList:
                edges[v].append(u)
            return edges

        def isCyclic(V, edges):
            adj = constructEdges(V, edges)
            print(adj)
            visited = [False] * V
            recStack = [False] * V

            for i in range(V):
                if not visited[i] and dfs(adj, i, visited, recStack):
                    return False

            return True

        return isCyclic(numCourses, prerequisites)

        