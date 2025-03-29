/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findmiddle(struct ListNode* head){
    struct ListNode* slow=head;
    struct ListNode* fast=head->next;       //modified tortoise and hare for even numbered linked list split
    while(fast!=NULL && fast->next!=NULL){
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
    struct ListNode* temp1=left;
    struct ListNode* temp2=right;

    while (temp1!= NULL && temp2!= NULL) {
        if (temp1->val > temp2->val) {
            temp->next = temp2;
            temp=temp2;
            temp2=temp2->next;
        } else {
            temp->next = temp1;
            temp=temp1;
            temp1=temp1->next;
        }
    }
    
    if (temp1) {
        temp->next = temp1;
    } else {
        temp->next = temp2;
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
