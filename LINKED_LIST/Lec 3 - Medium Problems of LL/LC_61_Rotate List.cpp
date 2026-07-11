/*Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3] */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        k %= n;
        if (k == 0)
            return head;
        tail->next = head;
        int steps = n - k - 1;
        ListNode* newTail = head;
        while (steps--) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};