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
        copyMap = collections.defaultdict(lambda: Node(0))
        copyMap[None] = None

        curr = head
        while curr:
            copyMap[curr].val = curr.val
            copyMap[curr].next = copyMap[curr.next]
            copyMap[curr].random = copyMap[curr.random]

            curr = curr.next

        return copyMap[head]
