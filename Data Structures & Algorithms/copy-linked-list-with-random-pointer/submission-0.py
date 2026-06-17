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
        if not head: return
        mp = {id(head): 0}
        copyHead = Node(head.val)
        nodeList = [copyHead]
        copyHeadNode = copyHead
        curr = head
        i = 0
        while curr.next:
            curr = curr.next
            i += 1
            copyHeadNode.next = Node(curr.val)
            copyHeadNode = copyHeadNode.next
            nodeList.append(copyHeadNode)
            mp[id(curr)] = i

        curr = head
        copyHeadNode = copyHead

        while curr.next:
            randomNode = curr.random
            randomIndex = -1 if not randomNode else mp[id(randomNode)]
            
            copyHeadNode.random = None if randomIndex == -1 else nodeList[randomIndex]

            curr = curr.next
            copyHeadNode = copyHeadNode.next
        randomNode = curr.random
        randomIndex = -1 if not randomNode else mp[id(randomNode)]
        copyHeadNode.random = None if randomIndex == -1 else nodeList[randomIndex]

        return copyHead
