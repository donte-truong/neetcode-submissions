# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next: return None
        length = 1
        node = head
        while node.next:
            node = node.next
            length += 1
        node = head
        prev = start = ListNode(next=node)
        for i in range(length-n):
            prev = node
            node = node.next
        if prev: prev.next = node.next
        return start.next