class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        nodes = {i: set() for i in range(numCourses)}
        reverse = {i: [] for i in range(numCourses)}
        for crs, pre in prerequisites:
            nodes[crs].add(pre)
            reverse[pre].append(crs)

        res = []
        taken = set()

        valid = True
        while len(res) < numCourses and valid:
            valid = False
            newNodes = {}
            for crs in nodes:
                if len(nodes[crs]) == 0:
                    valid = True
                    res.append(crs)
                    taken.add(crs)
                    for after in reverse[crs]:
                        nodes[after].remove(crs)
                else:
                    newNodes[crs] = nodes[crs]
            nodes = newNodes

        return [] if not valid else res
