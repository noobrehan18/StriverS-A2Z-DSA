/* Find Pairs with Given Sum in Doubly Linked List

Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.

Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.
Examples:
Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7
Output: [[1, 6], [2, 5]]
Explanation: 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.
Input: head = [1, 5, 6], target = 6
Output: [[1, 5]]
Explanation: 1 + 5 = 6 is the only valid pair.*/


//optimal approach

class Solution {
public:
    
    ListNode* findTail(ListNode* head) {
        ListNode* tail = head;
        while (tail->next != nullptr) tail = tail->next;
        return tail;
    }

    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;
        if (head == nullptr) return ans;

        ListNode* left = head;
        ListNode* right = findTail(head);

        while (left != nullptr && right != nullptr && left->val < right->val) {
            int sum = left->val + right->val;
            if (sum == target) {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            } else if (sum < target) {
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return ans;
    }
};
