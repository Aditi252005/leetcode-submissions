class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode* head,ListNode* r){
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr && curr!=r){
            ListNode* curNext=curr->next;

            curr->next=prev;
            prev=curr;
            curr=curNext;
        }
        return {prev,head};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l=head;
        while(l && left-1>0) {l=l->next;left--;}

        ListNode* r=head;
        while(r && right) {r=r->next;right--;}

        ListNode*temp=head;
        while(temp && temp->next!=l) temp=temp->next;
        
        auto [a,b]= reverse(l,r);

        if(temp) temp->next=a;
        else head=a;
        b->next=r;
        
        
        return head;
    }
};