// recurvsive approach

class Solution {
public:
    int addHelper(ListNode* node) {
        if (node == NULL)
            return 1;
        int carry = addHelper(node->next);
        node->val += carry;
        if (node->val < 10)
            return 0;
        node->val = 0;
        return 1;
    }

    ListNode* addOne(ListNode* head) {
        int carry = addHelper(head);
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

