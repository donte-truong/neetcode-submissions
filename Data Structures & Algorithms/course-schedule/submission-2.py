class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        nodes = {i: [] for i in range(numCourses)}
        for crs, pre in prerequisites:
            nodes[crs].append(pre)

        visiting = set()

        def detectCycle(crs):
            if crs in visiting:
                return True

            if nodes[crs] == []:
                return False

            visiting.add(crs)
            for pre in nodes[crs]:
                if detectCycle(pre):
                    return True
            visiting.remove(crs)
            nodes[crs] = []
            return False

        for node in nodes:
            if detectCycle(node):
                return False
        return True

        