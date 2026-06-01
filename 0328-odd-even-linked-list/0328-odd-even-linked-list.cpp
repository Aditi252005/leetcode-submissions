
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* o=head;
        ListNode* e=head->next;
        ListNode*temp=head->next;

        while(e && o && e->next && o->next){
            o->next=e->next;
            o=e->next;
            e->next=o->next;
            e=o->next;
        }

        o->next=temp;
        return head;
    }
};