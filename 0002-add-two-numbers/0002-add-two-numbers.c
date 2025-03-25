/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyhead=(struct ListNode *)malloc(sizeof(struct ListNode));
    dummyhead->val=0;
    dummyhead->next=NULL;
    struct ListNode *curr=dummyhead;
    int carry=0;
    int data1,x,y;
    while(l1!=NULL || l2!=NULL || carry!=0){
        if (l1!=NULL){
            x=l1->val;
        }else{
            x=0;
        }
        if (l2!=NULL){
            y=l2->val;
        }else{
            y=0;
        }
        data1=x+y+carry;
        carry=data1/10;
        struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->val=data1%10;
        newnode->next=NULL;
        curr->next=newnode;
        curr=curr->next;
        if (l1!=NULL){
            l1=l1->next;
        }
        if (l2!=NULL){
            l2=l2->next;
        }
    }
    return dummyhead->next;
}