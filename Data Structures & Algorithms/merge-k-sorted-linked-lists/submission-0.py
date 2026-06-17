# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head = ListNode()
        headNode = head

        while True:
            index, currMin = -1, float("infinity")
            for i in range(len(lists)):
                value = float("infinity") if not lists[i] else lists[i].val
                if value < currMin:
                    currMin = value
                    index = i
            if index == -1: break
            headNode.next = lists[index]
            headNode = headNode.next
            lists[index] = lists[index].next
        
        return head.next