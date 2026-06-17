class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 0, max(piles)

        while l < r-1:
            m = l + ((r-l)//2)
            hours = 0
            for pile in piles:
                hours += math.ceil(pile/m)

            if hours > h:
                l = m
            elif hours <= h:
                r = m

        return r

        