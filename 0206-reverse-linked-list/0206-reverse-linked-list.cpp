class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* rcur=NULL;
        while(curr){
           ListNode* n=new ListNode(curr->val);
           n->next=rcur;
           curr=curr->next;
           rcur=n;
        }
        return rcur;
    }
};