/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

int length(Node *head) {
 int cnt = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

//sheet qs-> 
/*Find the length of the Linked List


0

100
You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.
Examples:
Input: head = [1, 2, 3, 4, 5]
Output: 5
Input: head = [8, 6]
Output: 2
*/

//soltion->

class Solution {
public:
    int getLength(ListNode* head) {
        int cnt=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
};