class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        count = Counter(hand)

        for num in hand:
            if num in count:
                start = num
                while count[start-1]:
                    start -= 1

                while start <= num:
                    while count[start]:
                        for i in range(groupSize):
                            if not count[start+i]: return False
                            count[start+i] -= 1
                    start += 1

        return True