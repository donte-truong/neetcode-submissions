class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        nodes = {i: set() for i in range(n)}

        for flightSrc, flightDest, flightPrice in flights:
            nodes[flightSrc].add((flightDest, flightPrice))

        res = float("infinity")
        visited = set()
        def dfs(node, stops, length):
            if stops > k+1:
                return
            if node == dst:
                nonlocal res
                res = min(length, res)
            
            visited.add(node)
            for adj, price in nodes[node]:
                if adj not in visited:
                    dfs(adj, stops+1, length+price)
            visited.remove(node)
        
        dfs(src, 0, 0)
        return res if res != float("infinity") else -1
            
