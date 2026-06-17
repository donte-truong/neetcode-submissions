"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        oldToCopy = {None: None}
        
        curr = head
        while curr:
            copy = Node(curr.val)
            oldToCopy[curr] = copy
            curr = curr.next

        curr = head
        while curr:
            copyNext = oldToCopy[curr.next]
            copyRandom = oldToCopy[curr.random]
            
            oldToCopy[curr].next = copyNext
            oldToCopy[curr].random = copyRandom

            curr = curr.next

        return oldToCopy[head]
