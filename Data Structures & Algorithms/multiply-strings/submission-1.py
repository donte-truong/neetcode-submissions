class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        mp = {c: i for i, c in enumerate("0123456789")}
        reverse = {i: c for i, c in enumerate("0123456789")}

        n1 = 0
        n2 = 0
        mult = 1
        for i in range(len(num1)-1, -1, -1):
            c = num1[i]
            n1 += mp[c]*mult
            mult *= 10
        mult = 1
        for j in range(len(num2)-1, -1, -1):
            c = num2[j]
            n2 += mp[c]*mult
            mult *= 10

        res = n1*n2
        if res == 0: return "0"
        output = ""
        while res:
            output += reverse[res % 10]
            res //= 10
        return output[::-1]