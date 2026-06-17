class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        edges = [[] for _ in range(numCourses)]
        for u, v in prerequisites:
            edges[v].append(u)

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

        visited = [False]*numCourses
        recStack = [False]*numCourses
        for V in range(numCourses):
            if not visited[V] and dfs(edges, V, visited, recStack):
                return False
        return True

        