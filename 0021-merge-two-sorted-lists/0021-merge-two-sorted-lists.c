/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* templ1=list1;
    struct ListNode* templ2=list2;
    struct ListNode* current=NULL;
    struct ListNode* head=NULL;
    while(templ1!=NULL && templ2!=NULL){
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->next=NULL;
        if(current!=NULL){
            current->next=newnode;
        }
        if(head==NULL){
            head=newnode;
        }
        current=newnode;
        if (templ1->val<templ2->val){
            newnode->val=templ1->val;
            templ1=templ1->next;
        }else{
            newnode->val=templ2->val;
            templ2=templ2->next;
        }
    }
    while(templ1!=NULL){
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=templ1->val;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        if(current!=NULL){
            current->next=newnode;
        }
        current=newnode;
        templ1=templ1->next;
    }
    while(templ2!=NULL){
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=templ2->val;
        newnode->next=NULL;
        if(current!=NULL){
            current->next=newnode;
        }
        if(head==NULL){
            head=newnode;
        }
        current=newnode;
        templ2=templ2->next;
    }
    return head;
}