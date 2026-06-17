# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        sumDummy = ListNode(0)
        sumNode = sumDummy
        l1Node, l2Node = l1, l2
        while l1Node or l2Node:
            l1Value = 0 if not l1Node else l1Node.val
            l2Value = 0 if not l2Node else l2Node.val
            value = l1Value + l2Value + carry
            carry = value//10
            value = value % 10
            sumNode.next = ListNode(value)
            sumNode = sumNode.next
            l1Node = None if not l1Node else l1Node.next
            l2Node = None if not l2Node else l2Node.next
        if carry: sumNode.next = ListNode(1)
        return sumDummy.next