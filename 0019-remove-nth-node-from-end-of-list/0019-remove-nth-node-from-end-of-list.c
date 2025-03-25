/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *temp=head;
    int count=1;
    int size=0;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    temp=head;
    if (size==n){
        if(temp!=NULL){
            head=temp->next;
        }
    }else{
        struct ListNode* prev=head;
        temp=temp->next;
        while(temp!=NULL){
            count=count+1;
            if(size-count+1==n){
                prev->next=prev->next->next;
            }
            prev=prev->next;
            temp=temp->next;
        }
    }
    return head;
}