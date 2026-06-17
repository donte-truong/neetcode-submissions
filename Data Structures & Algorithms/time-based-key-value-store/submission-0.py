class TimeMap:

    def __init__(self):
        self.timeMap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.timeMap:
            self.timeMap[key] = [(timestamp, value)]
        else:
            self.timeMap[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.timeMap or self.timeMap[key][0][0] > timestamp:
            return ""
        if timestamp > self.timeMap[key][-1][0]:
            return self.timeMap[key][-1][1]

        timeMapList = self.timeMap[key]
        l, r = 0, len(timeMapList)
        while l < r-1:
            m = (l+r)//2
            if timeMapList[m][0] < timestamp:
                l = m
            elif timeMapList[m][0] > timestamp:
                r = m
            else:
                return timeMapList[m][1]
        
        return timeMapList[l][1]
