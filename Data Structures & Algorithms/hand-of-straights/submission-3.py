class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        counter = Counter(hand)

        for num in sorted(hand):
            print(num)
            if num in counter and not num-1 in counter:
                size = 0
                val = num
                while val in counter and size < groupSize:
                    print(val, counter, end=" ")
                    size += 1
                    counter[val] -= 1
                    if counter[val] == 0:
                        del counter[val]
                    val += 1
                if size != groupSize: return False
        return True if not counter else False