class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        operators = {
            "+": lambda x, y: x+y,
            "-": lambda x, y: x-y,
            "*": lambda x, y: x*y,
            "/": lambda x, y: int(x/y)
        }
        for t in tokens:
            if t in operators:
                num2 = stack.pop()
                num1 = stack.pop()
                operation = operators[t]
                stack.append(operation(num1, num2))
            else:
                stack.append(int(t))

        return stack[0]