/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* start = dummy;
        ListNode* end = dummy;

        for (int i = 1; i <= right + 1; i++) {
            if (i < left) {
                start = start->next;
            }
            end = end->next;
        }

        ListNode* prev = end;
        ListNode* curr = start->next;
        while (curr != end) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        start->next = prev;

        return dummy->next;
    }
};