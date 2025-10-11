                            // brute force (hashing) 
int lengthOfLoop(Node *head) {
    unordered_map<Node*, int> mpp;

    Node* temp = head;
    int timmer = 0;
    while (temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            int loopLength = timmer - mpp[temp];
            return loopLength;
        }
        mpp[temp] = timmer;
        temp = temp->next;
        timmer++;
    }
  
    return 0;
}



                // optimal - tortoise and hare algo

int findeLength(Node *slow, Node *fast) {
  int cnt = 0; 
  do {
    cnt++;
    fast = fast->next;
  } while (slow != fast);

  return cnt;
}


int lengthOfLoop(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {

      return findeLength(slow, fast);
    }
  }
  return 0;
}


//SHEEET QS--
/*Length of loop in LL


0

100
Medium

Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.

A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.

Note that pos is not passed as a parameter.
Examples:

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1
Output: 4
Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.*/


//SOLTION-->

class Solution {
public:
    int findLength(ListNode *slow, ListNode *fast) {
        int cnt=1;
        fast=fast->next;
        while(slow!=fast){
            cnt++;
            fast=fast->next;
        }
        return cnt;
    }

    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                return findLength(slow,fast);
            }
        }
        return 0;

    }
};