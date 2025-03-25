/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* temp=head;
    int data;
    while(temp!=NULL && temp->next!=NULL){
        data=temp->val;
        temp->val=temp->next->val;
        temp->next->val=data;
        if(temp->next->next!=NULL){
            temp=temp->next->next;
        }
        else{
            temp=NULL;
        }
    }
    return head;
}