class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        while(prev->next!=slow) prev=prev->next;
        prev->next=slow->next;

        return head;
    }
};