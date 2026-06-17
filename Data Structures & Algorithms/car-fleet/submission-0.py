class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        fleets = 0
        stack = []
        times = []
        for i in range(len(position)):
            finishTime = (target-position[i])/speed[i]
            times.append((finishTime, position[i]))
        times.sort(key=lambda x: (x[0], x[1]))

        for time in times:
            while len(stack) > 0 and time[1] >= stack[-1]:
                stack.pop()
            stack.append(time[1])

        return len(stack)
