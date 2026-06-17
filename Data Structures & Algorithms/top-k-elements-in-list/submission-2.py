class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        countList = [[] for i in range(len(nums)+1)]
        countMap = Counter(nums)
        for key in countMap.keys():
            countList[countMap[key]].append(key)

        numbers = []
        for i in range(len(countList)-1, -1, -1):
            if len(countList[i]) != 0:
                for j in range(0, len(countList[i])):
                    numbers.append(countList[i][j])
                    if len(numbers) == k:
                        return numbers