
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        if(!head || !head->next) return false;
        ListNode* fast=head->next->next;

        while(fast){
            if(slow==fast) return true;
            slow=slow->next;
            if(!fast->next) break;
            fast=fast->next->next;
        }
        return false;
    }
};