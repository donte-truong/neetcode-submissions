# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1: return list2
        if not list2: return list1
        head = list1 if list1.val <= list2.val else list2
        
        node1 = list1
        node2 = list2

        while node1 and node2:
            if node1.val <= node2.val:
                temp = node1.next
                if not temp or temp.val > node2.val:
                    node1.next = node2
                node1 = temp
            else:
                temp = node2.next
                if not temp or temp.val >= node1.val:
                    node2.next = node1
                node2 = temp

        return head