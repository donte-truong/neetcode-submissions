# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1: return head
        newHead = head
        curr = head
        prev = None
        tail = None
        i = k
        done = False
        while curr:
            prev = None
            first = curr
            i = 0
            while curr and i<k:
                after = curr.next
                curr.next = prev
                prev = curr
                curr = after
                i += 1
            if not curr and i<k and not done:
                curr = prev
                done = True
                continue
            if newHead == head: newHead = prev
            if tail: tail.next = prev
            tail = first
        return newHead
