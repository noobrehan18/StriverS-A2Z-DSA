            //sheet qs-->
        /*Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

        Return the head of the modified linked list.
        Examples:
        Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
        Output: head -> 1 <-> 3 <-> 4 <-> 5
        Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
        The underlined nodes were deleted to get the desired result.
        Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2
        Output: head -> 1 <-> 2
        Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2
        The underlined nodes were deleted to get the desired result.*/


class Solution {
public:
    ListNode* removeDuplicates(ListNode* head) {
        ListNode* temp = head;
        
        while(temp != NULL && temp->next != NULL) {
            ListNode* nextNode = temp->next;
            while(nextNode != NULL && nextNode->val == temp->val) {
                ListNode* duplicates = nextNode;
                nextNode = nextNode->next;
                delete duplicates; 
            }
            temp->next = nextNode;
            if(nextNode != NULL) nextNode->prev = temp;

            temp = temp->next;
        }
        return head;
    }
};

