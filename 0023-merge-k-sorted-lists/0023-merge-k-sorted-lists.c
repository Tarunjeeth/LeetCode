/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* left,struct ListNode* right){
    struct ListNode* dummyhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->val=-1;
    dummyhead->next=NULL;
    struct ListNode* temp=dummyhead;
    struct ListNode* temp1=left;
    struct ListNode* temp2=right;
    while(temp1!=NULL && temp2!=NULL){
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->next=NULL;
        if (temp1->val<temp2->val){
            newnode->val=temp1->val;
            temp->next=newnode;
            temp1=temp1->next;
            temp=temp->next;
        }else{
            newnode->val=temp2->val;
            temp->next=newnode;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    if(temp1!=NULL){
        temp->next=temp1;
    }
    if(temp2!=NULL){
        temp->next=temp2;
    }
    return dummyhead->next;
}

struct ListNode* findmiddle(struct ListNode* head){
    struct ListNode* slow=head;
    struct ListNode* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct ListNode* mergesort(struct ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    struct ListNode* mid=findmiddle(head);
    struct ListNode* left=head;
    struct ListNode* right=mid->next;
    mid->next=NULL;
    left=mergesort(left);
    right=mergesort(right);
    return merge(left,right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i=0;
    struct ListNode* dummyhead=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* head;
    dummyhead->val=-1;
    dummyhead->next=NULL;
    struct ListNode* temp=dummyhead;
    while(i<listsSize){
        head=lists[i];
        if (head!=NULL){
            temp->next=head;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        i=i+1;
    }

    return mergesort(dummyhead->next);
}