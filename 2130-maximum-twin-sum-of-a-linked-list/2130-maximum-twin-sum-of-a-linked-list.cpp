class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* cur=head;
        ListNode* prev=NULL;

        while(cur){
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* rev=reverse(slow);
        ListNode* cur=head;

        int sum=0;
        while(rev){
            sum=max(sum,cur->val+rev->val);
            cur=cur->next;
            rev=rev->next;
        }
        return sum;
    }
};