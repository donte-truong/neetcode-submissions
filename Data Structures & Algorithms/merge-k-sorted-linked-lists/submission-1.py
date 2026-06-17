# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists) == 0: return None
        if len(lists) == 2:
            mergedHead = self.mergeList(lists[0], lists[1])
            return mergedHead
        elif len(lists) == 1:
            return lists[0]
        middle = len(lists)//2
        left = self.mergeKLists(lists[:middle])
        right = self.mergeKLists(lists[middle:])
        return self.mergeList(left, right)

    def mergeList(self, l1, l2) -> ListNode:
        head = ListNode()
        headNode = head
        while l1 or l2:
            if not l2 or (l1 and l1.val <= l2.val):
                headNode.next = l1
                l1 = l1.next
            elif not l1 or (l2 and l1.val > l2.val):
                headNode.next = l2
                l2 = l2.next
            headNode = headNode.next
        return head.next