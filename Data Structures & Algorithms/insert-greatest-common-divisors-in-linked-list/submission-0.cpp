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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        while (second) {
            ListNode* gcd = new ListNode(getGCD(first->val, second->val));
            first->next = gcd;
            gcd->next = second;
            first = second;
            second = second->next;
        }
        return head;
    }

private:
    int getGCD(int a, int b) {
        int shift = 0;
        while ((a | b) & 1 == 0) {
            a >>= 1;
            b >>= 1;
            shift++;
        }

        while (a & 1 == 0)
            a >>= 1;

        while (b != 0) {
            while (b & 1 == 0)
                b >>= 1;

            if (b > a)
                swap(a, b);

            a -= b;
        }

        return a << shift;
    }
};