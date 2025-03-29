/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findmiddle(struct ListNode* head){
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct ListNode* mergeList(struct ListNode* left, struct ListNode* right) {
    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->val = -1;
    dummyhead->next = NULL;
    struct ListNode* temp = dummyhead;
    
    while (left != NULL && right != NULL) {
        if (left->val > right->val) {
            temp->next = right;
            right = right->next;
        } else {
            temp->next = left;
            left = left->next;
        }
        temp = temp->next;
    }
    
    if (left) {
        temp->next = left;
    } else {
        temp->next = right;
    }

    return dummyhead->next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode* mid=findmiddle(head);
    struct ListNode* left=head;
    struct ListNode* right=mid->next;
    mid->next=NULL;

    left=sortList(left);
    right=sortList(right);
    return mergeList(left,right);
}
