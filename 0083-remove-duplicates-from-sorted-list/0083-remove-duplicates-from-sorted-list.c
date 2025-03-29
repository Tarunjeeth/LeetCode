/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current=head;
    int currentval;
    struct ListNode* temp;
    if(current==NULL || current->next==NULL){
        return head;
    }
    while(current!=NULL && current->next!=NULL){
        currentval=current->val;
        temp=current;
        while(temp->next!=NULL && temp->next->val==currentval){
            temp=temp->next;
        }
        if(current!=temp){
            current->next=temp->next;
        }
        current=current->next;
    }
    return head;
}