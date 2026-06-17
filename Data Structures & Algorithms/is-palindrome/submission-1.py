class Solution:
    def isPalindrome(self, s: str) -> bool:
        stripString = ""
        for char in s:
            if char.isalnum():
                stripString += char.lower()
        leftPointer = (len(stripString)//2)-1
        if (len(stripString) % 2 == 0):
            rightPointer = leftPointer + 1
        else: 
            rightPointer = leftPointer + 2
        for i in range(len(stripString)//2):
            if stripString[leftPointer] != stripString[rightPointer]:
                return False
            leftPointer -= 1
            rightPointer += 1
        return True
