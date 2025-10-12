// bruthe  force (two pass soltion)--

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int res=n/2;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0){
                ListNode* middle=temp->next;
                temp->next=temp->next->next;
                delete(middle);
            }
            temp=temp->next;
        }return head;       
    }
};
// one pass soltion---> 

ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        fast = fast->next->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midNode = slow->next;
        slow->next = slow->next->next;
        delete midNode;
        return head;
    }