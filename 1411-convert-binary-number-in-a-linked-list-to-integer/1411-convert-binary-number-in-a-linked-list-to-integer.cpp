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
    int pow(int power){
        int value=1;
        for (int i=0;i<power;i++){
            value=value*2;
        }
        return value;
    }
    int getSize(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count=count+1;
            temp=temp->next;
        }
        return count;
    }
    int getDecimalValue(ListNode* head) {
        int size=getSize(head);
        size=size-1;
        int decimal=0;
        ListNode* temp=head;
        while(temp!=NULL){
            if (temp->val!=0){
                decimal+=pow(size);
            }
            size=size-1;
            temp=temp->next;
        }
        return decimal;
    }
};