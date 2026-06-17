class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = []
        
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            digit = digits[i]
            digit += carry
            if digit > 9:
                digit = 0
                carry = 1
            else:
                carry = 0
            res.append(digit)
        if carry: res.append(carry)
        res.reverse()
        return res