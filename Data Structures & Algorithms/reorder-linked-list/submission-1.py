# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head.next: return
        length = 1
        node = head
        while node.next:
            node = node.next
            length += 1
        middle = length // 2
        prev = None
        curr = head
        for i in range(length):
            after = curr.next
            if i == middle:
                prev = curr
                prev.next = None
            elif prev:
                after = curr.next
                curr.next = prev
                prev = curr
            curr = after
        forward = head 
        backward = prev
        switch = True
        while forward.next and backward.next:
            if switch:
                after = forward.next
                forward.next = backward
                forward = after
            else:
                after = backward.next
                backward.next = forward
                backward = after
            switch = not switch