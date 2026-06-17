class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        nodes = {i: [] for i in range(numCourses)}
        for crs, pre in prerequisites:
            nodes[crs].append(pre)

        visiting = set()

        def dfs(crs):
            if crs in visiting:
                return False
            if nodes[crs] == []:
                return True

            visiting.add(crs)
            for pre in nodes[crs]:
                if not dfs(pre):
                    return False
            visiting.remove(crs)
            nodes[crs] = []
            return True

        for node in nodes:
            if not dfs(node):
                return False
        return True

        