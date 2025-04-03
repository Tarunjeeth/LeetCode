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
    void reverse(ListNode* node){
        ListNode* currentnode=node;
        ListNode* nextnode=node;
        ListNode* prevnode=NULL;
        while(nextnode!=NULL){
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
    }
    ListNode* findknode(ListNode* node,int k){
        k=k-1;
        ListNode* temp=node;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* nextnode;
        ListNode* prevnode=NULL;
        ListNode* kthnode;
        while(temp!=NULL){
            kthnode=findknode(temp,k);
            if (kthnode==NULL){
                if (prevnode){
                    prevnode->next=temp;
                }
                break;
            }
            nextnode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            if (temp==head){
                head=kthnode;
            }
            else{
                prevnode->next=kthnode;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};