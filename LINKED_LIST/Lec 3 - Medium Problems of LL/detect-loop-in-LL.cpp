//brute force using hashing
map<node*int>mpp;
temp=head;
while(temp!=NULL){
    if(mpp[temp]==1) return true;
    mpp[temp]=1;
    temp=temp->next;
}
return false;

// optimal using tortoise & hare algo

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}
