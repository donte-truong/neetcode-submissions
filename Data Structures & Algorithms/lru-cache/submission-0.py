class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.mp = {}
        self.stack = collections.deque()

    def get(self, key: int) -> int:
        value = -1 if key not in self.mp else self.mp[key]["val"]
        if value != -1:
            self.mp[key]["count"] += 1
            self.stack.append(key)
        return value

    def put(self, key: int, value: int) -> None:
        self.mp[key] = {
            "val": value,
            "count": 1 if key not in self.mp else (1+self.mp[key]["count"])
        }
        self.stack.append(key)
        while len(self.mp) > self.capacity:
            oldest = self.stack.popleft()
            self.mp[oldest]["count"] -= 1
            if self.mp[oldest]["count"] == 0:
                del self.mp[oldest]
