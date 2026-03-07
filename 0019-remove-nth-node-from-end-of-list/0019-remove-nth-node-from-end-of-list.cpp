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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int l=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            l++;
            temp=temp->next;
        }
        if(l==1) return NULL;
        int t=l-n+1;
        t--;//3
        if(t==0) return head->next;
        temp=head;
        while(t>1){
            temp=temp->next;
            t--;
        }
        temp->next=temp->next->next;
        return head;
    }
};