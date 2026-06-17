class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        nodes = {i: set() for i in range(numCourses)}
        reverse = {i: [] for i in range(numCourses)}
        for crs, pre in prerequisites:
            nodes[crs].add(pre)
            reverse[pre].append(crs)

        res = []
        valid = True
        while len(res) < numCourses and valid:
            valid = False
            for crs in nodes:
                if len(nodes[crs]) == 0:
                    valid = True
                    res.append(crs)
                    for after in reverse[crs]:
                        nodes[after].remove(crs)
                    nodes[crs] = {-1}
        return [] if not valid else res
