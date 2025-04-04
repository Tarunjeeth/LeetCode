/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int leng(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    int deleteAtEnd(ListNode* head){
        int data;
        ListNode* temp=head;
        if (temp==NULL){
            return NULL;
        }
        while(temp!=NULL && temp->next!=NULL && temp->next->next!=NULL){
            temp=temp->next;
        }
        if(temp!=NULL && temp->next!=NULL){
            data=temp->next->val;
            temp->next=NULL;
        }
        
        return data;
    }
    ListNode* insertatbeginning(ListNode* head,int data){
        ListNode* newnode=new ListNode(data);
        newnode->next=head;
        return newnode;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int data;
        ListNode* newn=head;
        if (head==NULL || head->next==NULL){
            return head;
        }
        else{
            int len=k%leng(head);    
            for (int i=0;i<len;i++){
                data=deleteAtEnd(newn);
                newn=insertatbeginning(newn,data);
            }
            return newn;
        }
    }
};