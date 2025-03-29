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
    ListNode* reverseList(ListNode* head) {
        ListNode* currentnode=head;
        ListNode* nextnode=head;
        ListNode* prevnode=NULL;
        while(nextnode!=NULL){
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        head=prevnode;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead=new ListNode();
        dummyhead->val=-1;
        dummyhead->next=NULL;
        ListNode* temp=dummyhead;
        ListNode* newl1=reverseList(l1);
        ListNode* temp1=newl1;
        ListNode* newl2=reverseList(l2);
        ListNode* temp2=newl2;
        int carry=0;
        int sum,x,y;
        while (temp1!=NULL || temp2!=NULL || carry!=0){
            if (temp1!=NULL){
                x=temp1->val;
            }else{
                x=0;
            }
            if (temp2!=NULL){
                y=temp2->val;
            }else{
                y=0;
            }
            sum=carry+x+y;
            carry=sum/10;
            sum=sum%10;
            ListNode* newnode=new ListNode();
            newnode->val=sum;
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;
            if (temp1!=NULL){
                temp1=temp1->next;
            }
            if (temp2!=NULL){
                temp2=temp2->next;
            }
        }
        return reverseList(dummyhead->next);
    }
};