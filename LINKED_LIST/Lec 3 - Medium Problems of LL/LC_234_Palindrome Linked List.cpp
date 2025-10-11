/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false
 
Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

//SOLTION--- // BRUTH FORCE (USING STACK)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<int> st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->val != st.top()){
                return false;
            }
            temp=temp->next;
            st.pop();
        }
        return true;
        
    }
};

//OPTIMAL APPROACH-->


ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find the middle of the linked list
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode *newHead = reverseLL(slow->next);

    // Step 3: Compare the two halves
    ListNode *first = head;
    ListNode *second = newHead;
    bool isPal = true;
    while (second != NULL)
    {
        if (first->val != second->val)
        {
            isPal = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore the original list
    slow->next = reverseLL(newHead);

    return isPal;
}