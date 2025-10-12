                //sheet qs


/*Delete all occurrences of a key in DLL


0

100
Hard

Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.
Examples:
Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
Output: head -> 2 <-> 3 <-> 4
Explanation: All nodes with the value 1 were removed.
Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2
Output: head -> 3 <-> -1 <-> 4
Explanation: All nodes with the value 2 were removed.
Note that the value of head is changed.*/

//soltion-->
class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val==target){
                if(temp==head){
                    head=head->next;
                }
                ListNode* nextNode=temp->next;
                ListNode* prevNode=temp->prev;

                if(nextNode) nextNode->prev=prevNode;
                if(prevNode)prevNode->next=nextNode;
                free(temp);
                temp=nextNode;
            }
            else{
                temp=temp->next;
            }

        }
        return head;

    }
};